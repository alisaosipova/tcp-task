#include "TCPServer.h"
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

TCPServer::TCPServer(int port) : serverPort(port) {}

void TCPServer::run() {
    startListening();
}

/**
 * @brief Listens for incoming connections on the specified port
 */
void TCPServer::startListening() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Failed to create socket.\n";
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed.\n";
        close(serverSocket);
        return;
    }

    if (listen(serverSocket, 10) < 0) {
        std::cerr << "Listen failed.\n";
        close(serverSocket);
        return;
    }

    std::cout << "Server is listening on port " << serverPort << "\n";

    while (true) {
        sockaddr_in clientAddr{};
        socklen_t clientLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen);

        if (clientSocket >= 0) {
            std::thread clientThread(&TCPServer::handleClient, this, clientSocket);
            clientThread.detach();
        }
    }

    close(serverSocket);
}

/**
 * @brief Handles the connection and communication with a single client
 * @param clientSocket The socket descriptor for the connected client
 */
void TCPServer::handleClient(int clientSocket) {
    char buffer[1024] = {0};
    int bytesRead = recv(clientSocket, buffer, 1024, 0);
    
    if (bytesRead > 0) {
        std::string message(buffer, bytesRead);
        logMessage(message);
    }
    
    close(clientSocket);
}

/**
 * @brief Logs the received message to the log file
 * @param message The message to be logged
 */
void TCPServer::logMessage(const std::string& message) {
    
    std::lock_guard<std::mutex> lock(logMutex);
    std::ofstream logFile("log.txt", std::ios::app);
    
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}
