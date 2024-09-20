#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <string>

/**
 * @brief TCPClient class handles the client-side functionality of connecting to a server and sending messages.
 */
class TCPClient {
public:
    TCPClient(const std::string& name, int port, int interval);
    
    void run();
private:
    std::string clientName;
    int serverPort;
    
    int connectInterval;
    std::string getCurrentTimestamp();
    
    void sendMessage();
};

#endif
