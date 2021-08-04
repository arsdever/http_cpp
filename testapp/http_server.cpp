#include <array>
#include <boost/asio.hpp>
#include <boost/test/unit_test.hpp>
#include <condition_variable>
#include <mutex>
#include <thread>

using namespace boost::asio::ip;

BOOST_AUTO_TEST_SUITE(http_client_suite)
boost::asio::io_service ctx;
tcp::socket				socket(ctx);

BOOST_AUTO_TEST_CASE(connect_test)
{
	tcp::resolver		 resolver { ctx };
	tcp::resolver::query query { "google.com", "80" };

	resolver.async_resolve(query, [](boost::system::error_code const& ec, tcp::resolver::iterator it) {
		if (ec)
			{
				std::cout << "ERROR: " << ec.message() << std::endl;
				return;
			}
		socket.async_connect(*it, [](boost::system::error_code const& ec) {
			std::array<char, 2048> data_buf { 0 };

			socket.async_read_some(boost::asio::buffer(data_buf.data(), data_buf.size()),
								   [ &data_buf ](boost::system::error_code const& ec, size_t bytes_transferred) {
									   if (ec)
										   {
											   std::cout << "ERROR: " << ec.message() << std::endl;
											   return;
										   }

									   std::cout.write(data_buf.data(), bytes_transferred).flush();
									   ctx.stop();
								   });
			socket.write_some(boost::asio::buffer("GET / HTTP/1.1\r\n\r\n"));
		});
	});

	ctx.run();
}

BOOST_AUTO_TEST_SUITE_END()