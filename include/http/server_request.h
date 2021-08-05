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
		server_request(request_method_t const& m, headers_t const& h, body_t const& b)
			: __method(m), __headers(h), __body(b)
		{
		}
		server_request(server_request const& o) { }
		server_request(server_request&& o) { }

		request_method_t method() const { return __method; }
		headers_t		 headers() const { return __headers; }
		body_t			 body() const { return __body; }

		friend std::ostream& operator<<(std::ostream& os, server_request const& req)
		{
			return os << request_method_to_string(req.method()) << ' ' << '/' << ' ' << "HTTP/1.1"
					  << "\r\n\r\n";
		}

	private:
		request_method_t __method;
		headers_t		 __headers;
		body_t			 __body;
	};
} // namespace http
