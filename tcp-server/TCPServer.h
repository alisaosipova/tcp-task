#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <string>
#include <thread>
#include <mutex>

/**
 * @brief TCPServer class handles the server-side functionality of accepting multiple clients and logging their messages.
 */
class TCPServer {
public:
    TCPServer(int port);
    
    void run(); 
private:
    int serverPort;
    std::mutex logMutex; 
    
    void handleClient(int clientSocket); 
    void logMessage(const std::string& message); 
    void startListening();
};

#endif
