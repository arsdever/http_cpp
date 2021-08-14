#include <boost/asio.hpp>
#include <boost/test/unit_test.hpp>
#include <http/rfc2616_response_parser.h>
#include <http/server_request_builder.h>

using namespace boost::asio::ip;
constexpr int BUFFER_SIZE = 4096;

BOOST_AUTO_TEST_SUITE(http_client_suite)
boost::asio::io_service ctx;
tcp::socket				socket(ctx);
boost::asio::streambuf	ibuffer;
boost::asio::streambuf	obuffer;

BOOST_AUTO_TEST_CASE(connect_test)
{
	tcp::resolver				resolver { ctx };
	tcp::resolver::results_type resolve_result = resolver.resolve("httpbin.org", "80");
	ctx.post([]() {});
	ctx.run();
	BOOST_CHECK(!resolve_result.empty());

	boost::system::error_code ec;
	if (socket.connect(*resolve_result.begin(), ec))
		{
			BOOST_FAIL(ec.message());
		}

	std::ostream								 request_stm(&obuffer);
	http::server_request_builder				 req_builder;
	http::server_request						 req { std::move(
		req_builder.with_method(http::request_method::RM_GET)
			.with_http_version(http::http_version::http_11)
			.with_path("/")
			.with_header({ http::request_header::known_header_enum::host, "httpbin.org" })
			.build()) };
	boost::asio::streambuf::mutable_buffers_type mbuffer = ibuffer.prepare(BUFFER_SIZE);
	request_stm << req;
	size_t b = boost::asio::write(socket, obuffer);

	std::string response_str;
	socket.wait(boost::asio::socket_base::wait_read);
	while (socket.available())
		{
			size_t bytes_read = socket.read_some(mbuffer, ec);

			if (ec)
				{
					BOOST_FAIL(ec.message());
				}

			response_str += std::string(boost::asio::buffer_cast<const char*>(ibuffer.data()), bytes_read);
		}

	http::rfc2616_response_parser parser;
	parser.parse(response_str.cbegin(), response_str.cend());

	auto response = parser.builder().build();

	BOOST_CHECK_EQUAL(response.http_version(), http::http_version::http_11);
	BOOST_CHECK_EQUAL(response.body().length(), response.content_length());
	BOOST_CHECK_EQUAL(std::stoi(response.headers()[ http::response_header::known_header_enum::content_length ].value()),
					  response.content_length());
}

BOOST_AUTO_TEST_SUITE_END()