#include <boost/test/unit_test.hpp>
#include <http/server_request_builder.h>

BOOST_AUTO_TEST_SUITE(request_test_suite)
BOOST_AUTO_TEST_CASE(request_method_functionality_test) { BOOST_CHECK_EQUAL(http::request_method::RM_GET, "GET"); }
BOOST_AUTO_TEST_CASE(request_builder_test)
{
	http::server_request_builder builder;
	std::string					 body = "{ \"body\" : \"true\" }";
	builder.with_method(http::request_method::RM_GET)
		.with_header(
			{ http::request_header::header_key_to_string(http::request_header::known_header_enum::authorization),
			  "Basic: None" })
		.with_body(body);
	http::server_request req { builder.build() };

	BOOST_CHECK_EQUAL(req.method(), http::request_method::RM_GET);
	BOOST_CHECK_EQUAL(req.headers().count(), 1);
	BOOST_CHECK_EQUAL(req.body(), body);
}
BOOST_AUTO_TEST_SUITE_END()
