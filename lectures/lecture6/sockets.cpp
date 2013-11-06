#include <enet/enet.h>
#include <iostream>
#include <boost/algorithm/string.hpp>

const int BUFFERSIZE=256;
const char *HOST="localhost";

//
// code must be cleaned up!!!!!!!!
//
void client(int port) {
    ENetHost  *client;
    ENetAddress  address;
    ENetEvent  event;
    ENetPeer  *peer;
    ENetPacket  *packet;
    char  buffer[BUFFERSIZE]; 
    client = enet_host_create(nullptr, 1, 2, 5760/8, 1440/8);

    if (client == nullptr) {
        std::cout << "Could not create client." << std::endl;
        return;
    }

    enet_address_set_host(&address, HOST);
    address.port = port;

    enet_host_service(client, &event, 1000);

    peer = enet_host_connect(client, &address, 2, 0);

    if (client == nullptr) {
        std::cout << "Could not connect to server." << std::endl;
        return;
    }

    while (true) {
        std::string message;
        std::cin >> message;
        std::cout << "sent: " << message << std::endl;
        packet = enet_packet_create(message.c_str(), message.size(), ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send (peer, 0, packet);
        while (enet_host_service(client, &event, 1000) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_RECEIVE:
                    std::cout << "received: " << static_cast<unsigned char *>(event.packet->data) << std::endl;
                    break;
            }
        }

    }
    enet_deinitialize();
}

void server(int port) 
{
    ENetAddress address;
    ENetHost * server;
    address.host = ENET_HOST_ANY;
    address.port = port;
    server = enet_host_create (&address, 32, 2, 0, 0);
    if (server == nullptr)
    {
        std::cerr << "error!" << std::endl;
        return;
    }
    ENetEvent  event;
    while(true) {
        while (enet_host_service(server, &event, 1000) > 0) {
            std::cout << "something..." << std::endl;
            switch (event.type) {
                case ENET_EVENT_TYPE_RECEIVE:
                    std::cout << "received: " << static_cast<unsigned char *>(event.packet->data) << std::endl;
                    break;
            }
        }
    }
    enet_host_destroy(server);
    enet_deinitialize();
}

int main(int argc, char * argv[])
{
    if(argc < 3) {
        std::cout << "usage:\n\tsockets server [port]\n\tsockets client [port]\n";
    }
    else {
        std::string kind = std::string(argv[1]);
        boost::algorithm::to_lower(kind);
        int port = atoi(argv[2]);

        std::cout << "starting port " << port << "." << std::endl;;

        if (enet_initialize() != 0) {
            std::cout <<"Could not initialize enet." << std::endl;
            return 0;
        }
        if(kind == "server") {
            std::cout << "serving..." << std::endl;
            server(port);
        }
        else if(kind == "client") {
            std::cout << "clienting..." << std::endl;
            client(port);
        }
        else {
            std::cerr << "no client or server started." << std::endl;
        }
    }
}

