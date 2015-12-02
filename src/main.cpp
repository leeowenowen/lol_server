#include <iostream>
#include <string> 

#include <boost/any.hpp>
#include <boost/asio.hpp> 
#include "fcgi_stdio.h"
#include <stdlib.h>

void printParam(std::string& buffer, const char* key)
{
    const char* value = getenv(key);
    if(!value) value = "";
    buffer += "\n";
    buffer += key;
    buffer += ":";
    buffer += value;
}

int main(void)
{
    std::string buffer;
    printParam(buffer, "SCRIPT_FILENAME");
    printParam(buffer, "QUERY_STRING");
    printParam(buffer, "REQUEST_METHOD");
    printParam(buffer, "CONTENT_TYPE");
    printParam(buffer, "CONTENT_LENGTH");
    printParam(buffer, "SCRIPT_NAME");
    printParam(buffer, "REQUEST_URI");
    printParam(buffer, "DOCUMENT_URI");
    printParam(buffer, "DOCUMENT_ROOT");
    printParam(buffer, "SERVER_PROTOCOL");
    printParam(buffer, "REQUEST_SCHEME");
    printParam(buffer, "HTTPS");
    printParam(buffer, "GATEWAY_INTERFACE");
    printParam(buffer, "SERVER_SOFTWARE");
    printParam(buffer, "REMOTE_ADDR");
    printParam(buffer, "REMOTE_PORT");
    printParam(buffer, "SERVER_ADDR");
    printParam(buffer, "SERVER_PORT");
    printParam(buffer, "SERVER_NAME");

    std::string output = 
        "Content-type: text/html\r\n"
        "\r\n"
        "<title>FastCGI Hello!</title>"
        "<h1>FastCGI Hello!</h1>";
        output += buffer;
        output += "Request number %d running on host <i>%s</i>\n";

    int count = 0;
    while (FCGI_Accept() >= 0)
        printf(output.c_str(),
                ++count, getenv("SERVER_NAME"));
    return 0;
}
//int main()
//{
//    std::string text = "test message";
//    boost::any value = text;
//    std::string text2 = boost::any_cast<std::string>(value);
//    std::cout << text2 << std::endl;
//}
//
//boost::asio::io_service io_service; 
//boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 80); 
//boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint); 
//boost::asio::ip::tcp::socket sock(io_service); 
//std::string data = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!"; 
//
//void write_handler(const boost::system::error_code &ec, std::size_t bytes_transferred) 
//{ 
//} 
//
//void accept_handler(const boost::system::error_code &ec) 
//{ 
//  if (!ec) 
//  { 
//    boost::asio::async_write(sock, boost::asio::buffer(data), write_handler); 
//  } 
//} 
//
//int main() 
//{ 
//  std::cout << "This is from main!" << std::endl;
//  acceptor.listen(); 
//  acceptor.async_accept(sock, accept_handler); 
//  io_service.run(); 
//}

