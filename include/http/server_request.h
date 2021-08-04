#pragma once

#include <http/headers.h>
#include <http/request_header.h>
#include <http/request_method.h>

namespace http
{
	class server_request
	{
	public:
		using request_method_t = request_method;
		using headers_t		   = headers<request_header>;
		using body_t		   = std::string;

	public:
		server_request() { }
		server_request(request_method_t const& m, headers_t const& h, body_t const& b) : __method(m), __headers(h), __body(b) { }
		server_request(server_request const& o) { }
		server_request(server_request&& o) { }

		request_method_t method() const { return __method; }
		headers_t headers() const { return __headers; }
		body_t body() const { return __body; }

	private:
		request_method_t __method;
		headers_t		 __headers;
		body_t			 __body;
	};
} // namespace http
