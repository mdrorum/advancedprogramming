#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void serving() {
}

void client_connected() {
}

int main()
{
    boost::asio::io_service io_service;
    //tcp_server server(io_service);
    io_service.run();

    tcp::endpoint endpoint(tcp::v4(), 1000);
    tcp::acceptor acceptor(io_service, endpoint);
    while(true) {
        acceptor.async_accept(io_service,
        [](boost::system::error_code ec)
        {
          if (!ec)
          {
            //std::make_shared<chat_session>(std::move(socket_), room_)->start();
          }

        });
    }
    return 0;
}

