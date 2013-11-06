#include <enet/enet.h>
#include <iostream>
#include <boost/algorithm/string.hpp>

const int BUFFERSIZE=256;

void client(int port) {
    ENetHost  *client;
    ENetAddress  address;
    ENetEvent  event;
    ENetPeer  *peer;
    ENetPacket  *packet;
    char  buffer[BUFFERSIZE]; 
    client = enet_host_create(NULL, 1, 2, 5760/8, 1440/8);

    peer = enet_host_connect(client, &address, 2, 0);

    while (true) {
        std::string message;
        std::cin >> message;
        packet = enet_packet_create(message.c_str(), strlen(buffer)+1, ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send (peer, 0, packet);
        while (enet_host_service(client, &event, 1000) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_RECEIVE:
                    std::cout << event.peer->data;
                    break;
            }
        }
    }
}

void server(int port) 
{
    ENetAddress address;
    ENetHost * server;
    address.host = ENET_HOST_ANY;
    address.port = 1234;
    server = enet_host_create (& address, 32, 2, 0, 0);
    if (server == NULL)
    {
        std::cerr << "error!" << std::endl;
        exit (EXIT_FAILURE);
    }
    else {
        ENetEvent  event;
        while(true) {
            while (enet_host_service(server, &event, 1000) > 0) {
                switch (event.type) {
                    case ENET_EVENT_TYPE_RECEIVE:
                        std::cout << event.peer->data;
                }
            }
        }
    }
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

        if(kind == "server") {
            server(port);
        }
        else if(kind == "client") {
            client(port);
        }
        else {
            std::cerr << "no client or server started." << std::endl;
        }
    }
}


//#include <iostream>
//#include <boost/asio.hpp>
//#include <boost/array.hpp>
//#include <boost/algorithm/string.hpp>

//using boost::asio::ip::udp;
//using namespace boost::asio;

//void server(int port) {
//boost::asio::io_service io_service;
////char recv_buf[256] ;
//boost::array<char, 128> buf;
//udp::endpoint remote_endpoint;
//boost::system::error_code ignored_error;
//udp::socket socket(io_service, udp::endpoint(udp::v4(), port)); 
//while(true) {
//socket.receive_from(boost::asio::buffer(buf), remote_endpoint, 0, ignored_error); 
//std::stringstream ss;
//std::string data(buf.begin(), buf.end());
//ss << "you said \"" << data << ".";
//socket.send_to(boost::asio::buffer(ss.str()), remote_endpoint, 0, ignored_error);
//}
//}

//void client(int port) {
//boost::asio::io_service io_service;
//boost::system::error_code ignored_error;
////char recv_buf[256] ;
//boost::array<char, 128> buf;
////udp::endpoint remote_endpoint;

//ip::udp::endpoint endpoint( ip::address::from_string("localhost"), port);

////udp::resolver resolver(io_service);
////udp::resolver::query query("localhost", "chat");
////udp::resolver::iterator endpoint_iterator = resolver.resolve(query);


//udp::socket socket(io_service);
//boost::asio::connect(socket, endpoint);

//while(true) {
//std::string message;
//std::cin >> message;

////socket.send_to(boost::asio::buffer(buf), remote_endpoint, 0, ignored_error);

//socket.receive_from(boost::asio::buffer(buf), endpoint, 128); 
////socket.receive
//socket.send_to(boost::asio::buffer(buf), endpoint);
////if (error == boost::asio::error::eof)
////{
////break; // Connection closed cleanly by peer.
////}
////else if (error)
////{
////throw boost::system::system_error(error); // Some other error.
////}
//std::string data(buf.begin(), buf.end());

////socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint, 0, ignored_error); 
//std::cout << "server said: " << data << "." << std::endl;
//}
//}

//int main(int argc, char * argv[])
//{
//if(argc < 3) {
//std::cout << "usage:\n\tsockets server [port]\n\tsockets client [port]\n";
//}
//else {
//std::string kind = std::string(argv[1]);
//boost::algorithm::to_lower(kind);
//int port = atoi(argv[2]);

//std::cout << "starting port " << port << "." << std::endl;;

//if(kind == "server") {
//server(port);
//}
//else if(kind == "client") {
//client(port);
//}
//else {
//std::cerr << "no client or server started." << std::endl;
//}
//}
//}

