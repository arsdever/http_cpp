#include <boost/asio.hpp>
#include <boost/test/unit_test.hpp>

#include <http/server_request_builder.h>

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
			boost::asio::streambuf buffer;
			boost::asio::streambuf req_buf;
			std::ostream		   request_stm(&req_buf);

			http::server_request_builder req_builder;
			http::server_request req { std::move(req_builder.with_method(http::request_method::RM_GET).build()) };

			socket.async_read_some(buffer, [ &buffer ](boost::system::error_code const& ec, size_t bytes_transferred) {
				if (ec)
					{
						std::cout << "ERROR: " << ec.message() << std::endl;
						return;
					}

				std::cout << std::istream(&buffer).rdbuf() << std::endl;
				ctx.stop();
			});

			request_stm << req;
			socket.write_some(req_buf);
		});
	});

	ctx.run();
}

BOOST_AUTO_TEST_SUITE_END()