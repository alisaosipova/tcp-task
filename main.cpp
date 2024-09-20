#include <iostream>
#include <string>
#include "tcp-client/TCPClient.h"
#include "tcp-server/TCPServer.h"

#define MAIN_ERR -1

/**
 * @brief Main entry point for either client or server, based on command-line arguments.
 * 
 * @param argc Number of command-line arguments
 * @param argv Command-line arguments
 * @return int Exit status of the program
 */

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage for server: ./server <port>\n";
        std::cerr << "Usage for client: ./client <name> <port> <interval>\n";
        return MAIN_ERR;
    }
    
    /* we determine the server or client by the first argument */
    std::string mode = argv[0];
    
    if (mode.find("server") != std::string::npos) {
        
        if (argc != 2) {
            std::cerr << "Invalid arguments for server.\n";
            return MAIN_ERR;
        }
        
        /* convert argument */
        int port = std::stoi(argv[1]);
        
        TCPServer server(port);
        server.run();
    } else if (mode.find("client") != std::string::npos) {
        
        if (argc != 4) {
            std::cerr << "Invalid arguments for client.\n";
            return MAIN_ERR;
        }
        
        /* convert arguments */
        std::string name = argv[1];
        int port = std::stoi(argv[2]);
        int interval = std::stoi(argv[3]);
        
        TCPClient client(name, port, interval);
        client.run();
    } else {
        std::cerr << "Unknown mode.\n";
        return MAIN_ERR;
    }

    return 0;
}
