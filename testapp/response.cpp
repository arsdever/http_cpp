#include <http/rfc2616_response_parser.h>
#include <http/server_response_builder.h>
#include <http/stdafx.h>
#include <http/ti_response_parser.h>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(response_test_suite)
static const std::string body = "nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices dui sapien eget mi "
								"proin sed libero enim sed faucibus";
static const std::string sample_response = "HTTP/1.1 200 OK\r\n"
										   "Date: Mon, 27 Jul 2009 12:28:53 GMT\r\n"
										   "Server: Apache/2.2.14 (Win32)\r\n"
										   "Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\r\n"
										   "Content-Length: 120\r\n"
										   "Content-Type: text/html\r\n"
										   "Connection: Closed\r\n"
										   "\r\n" +
										   body;

BOOST_AUTO_TEST_CASE(no_headers_no_body_test)
{
	std::string					  input = "HTTP/1.1 200 OK\r\n\r\n";
	// http::rfc2616_response_parser parser;
	http::ti_response_parser<http::rfc2616_response_parser> parser;
	parser.parse(input.cbegin(), input.cend());
	http::server_response response = parser.builder().build();

	BOOST_CHECK_EQUAL(response.headers().count(), 0);
}

BOOST_AUTO_TEST_CASE(multiline_header_test)
{
	std::string input = "HTTP/1.1 200 OK\r\n"
						"Content-Type: text/html\r\n"
						"\tapplication/json\r\n"
						" \ttext/*\r\n"
						" text/xml\r\n\r\n";
	http::rfc2616_response_parser parser;
	parser.parse(input.cbegin(), input.cend());
	http::server_response response = parser.builder().build();

	BOOST_CHECK_EQUAL(response.headers().count(), 1);
	BOOST_CHECK_EQUAL(response.headers()[ "Content-Type" ].key(), "Content-Type");
	BOOST_CHECK_EQUAL(response.headers()[ "Content-Type" ].value(), "text/html application/json text/* text/xml");
}

BOOST_AUTO_TEST_CASE(multiline_header_with_singleline_header_test)
{
	std::string input = "HTTP/1.1 200 OK\r\n"
						"Content-Type: text/html\r\n"
						"\tapplication/json\r\n"
						" \ttext/*\r\n"
						" text/xml\r\n"
						"Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\r\n"
						"\r\n";
	http::rfc2616_response_parser parser;
	parser.parse(input.cbegin(), input.cend());
	http::server_response response = parser.builder().build();

	BOOST_CHECK_EQUAL(response.headers().count(), 2);
	BOOST_CHECK_EQUAL(response.headers()[ "Content-Type" ].value(), "text/html application/json text/* text/xml");
	BOOST_CHECK_EQUAL(response.headers()[ "Last-Modified" ].value(), "Wed, 22 Jul 2009 19:15:56 GMT");
}

BOOST_AUTO_TEST_CASE(multiple_multiline_header_test)
{
	std::string input = "HTTP/1.1 200 OK\r\n"
						"Content-Type: text/html\r\n"
						"\tapplication/json\r\n"
						" \ttext/*\r\n"
						" text/xml\r\n"
						"Last-Modified: Wed,\r\n"
						" 22 Jul 2009 19:15:56 GMT\r\n"
						"\r\n";
	http::rfc2616_response_parser parser;
	parser.parse(input.cbegin(), input.cend());
	http::server_response response = parser.builder().build();

	BOOST_CHECK_EQUAL(response.headers().count(), 2);
	BOOST_CHECK_EQUAL(response.headers()[ "Content-Type" ].value(), "text/html application/json text/* text/xml");
	BOOST_CHECK_EQUAL(response.headers()[ "Last-Modified" ].value(), "Wed, 22 Jul 2009 19:15:56 GMT");
}

// http::server_response response = http::server_response::parse(sample_response);
BOOST_AUTO_TEST_CASE(status_line_test)
{
	http::rfc2616_response_parser parser;
	parser.parse(sample_response.cbegin(), sample_response.cend());
	http::server_response response = parser.builder().build();
	BOOST_CHECK_EQUAL(response.http_version(), http::http_version::http_11);
	BOOST_CHECK_EQUAL(response.status_code(), http::status_code::sc_ok);
	BOOST_CHECK_EQUAL((int)response.status_code(), 200);
	BOOST_CHECK_EQUAL(response.status_message(), "OK");
}

BOOST_AUTO_TEST_CASE(headers_test)
{
	http::rfc2616_response_parser parser;
	parser.parse(sample_response.cbegin(), sample_response.cend());
	http::server_response response = parser.builder().build();
	BOOST_CHECK_EQUAL(response.headers().count(), 6);
	BOOST_CHECK_EQUAL(http::response_header::header_key_from_string("Date"),
					  http::response_header::known_header_enum::date);
	BOOST_CHECK_EQUAL(response.headers()[ http::response_header::known_header_enum::date ].key(),
					  http::response_header::header_key_to_string(http::response_header::known_header_enum::date));
}

BOOST_AUTO_TEST_CASE(body_test)
{
	http::rfc2616_response_parser parser;
	parser.parse(sample_response.cbegin(), sample_response.cend());
	http::server_response response = parser.builder().build();
	BOOST_CHECK_EQUAL(response.content_length(), 120);
	BOOST_CHECK_EQUAL(std::stoi(response.headers()[ "Content-Length" ].value()), 120);
	BOOST_CHECK_EQUAL(response.body(), body);
	BOOST_CHECK_EQUAL(response.body().size(), body.size());
}
BOOST_AUTO_TEST_SUITE_END()
