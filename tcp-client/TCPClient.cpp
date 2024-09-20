#include "TCPClient.h"
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>

/**
 * @brief Construct a new TCPClient object
 * @param name The name of the client
 * @param port The server port to connect to
 * @param interval The time interval (in seconds) between each connection
 */
TCPClient::TCPClient(const std::string& name, int port, int interval)
    : clientName(name), serverPort(port), connectInterval(interval) {}

/**
 * @brief Starts the client loop to periodically connect to the server and send messages
 */
void TCPClient::run() {
    while (true) {
        sendMessage();
        std::this_thread::sleep_for(std::chrono::seconds(connectInterval));
    }
}

/**
 * @brief Get the current timestamp in the format [yyyy-mm-dd hh:mm:ss.ms]
 * @return A string containing the current timestamp
 */
std::string TCPClient::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    
    std::ostringstream timestamp;
    timestamp << std::put_time(std::localtime(&now_time_t), "[%Y-%m-%d %H:%M:%S");
    timestamp << '.' << std::setfill('0') << std::setw(3) << ms.count() << "] ";
    
    return timestamp.str();
}

/**
 * @brief Sends a message to the server containing the timestamp and the client name
 */
void TCPClient::sendMessage() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation failed.\n";
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connection to server failed.\n";
        close(sock);
        return;
    }

    std::string message = getCurrentTimestamp() + clientName;
    send(sock, message.c_str(), message.size(), 0);
    close(sock);
}

