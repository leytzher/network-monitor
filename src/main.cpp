#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>

#include <iostream>

using tcp = boost::asio::ip::tcp;

void Log(boost::system::error_code ec){
  std::cerr << (ec ? "Error: " : "OK")
	    << (ec ? ec.message() : "")
	    << std::endl;
}


int main()
{
  boost::asio::io_context ioc {};
  tcp::socket socket {ioc};

  boost::system::error_code ec {};
  tcp::resolver resolver {ioc};
  auto endpoint {resolver.resolve("google.com", "80", ec)};
  if (ec) {
    Log(ec);
    return -1;
  }
  socket.connect(*endpoint, ec);
  if (ec) {
    Log(ec);
    return -2;
  }
  Log(ec);
  return 0;



}
