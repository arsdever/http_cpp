#pragma once

#include <http/headers.h>
#include <http/http_version.h>
#include <http/request_header.h>
#include <http/request_method.h>

namespace http
{
	class server_request
	{
	public:
		using request_method_t = request_method;
		using http_version_t   = http_version;
		using headers_t		   = headers<request_header>;
		using string_t		   = std::string;
		using body_t		   = std::string;

	public:
		server_request() { }
		server_request(
			request_method_t const& m, string_t p, http_version_t const& v, headers_t const& h, body_t const& b)
			: __method(m), __path(p), __http_version(v), __headers(h), __body(b)
		{
		}
		server_request(server_request const& o)
			: __method(o.__method), __path(o.__path), __http_version(o.__http_version), __headers(o.__headers),
			  __body(o.__body)
		{
		}
		server_request(server_request&& o)
			: __method(std::move(o.__method)), __path(std::move(o.__path)), __http_version(std::move(o.__http_version)),
			  __headers(std::move(o.__headers)), __body(std::move(o.__body))
		{
		}

		request_method_t method() const { return __method; }
		headers_t		 headers() const { return __headers; }
		string_t		 path() const { return __path; }
		http_version_t	 http_version() const { return __http_version; }
		body_t			 body() const { return __body; }

		friend std::ostream& operator<<(std::ostream& os, server_request const& req)
		{
			return os << request_method_to_string(req.method()) << ' ' << req.path() << ' ' << req.http_version()
					  << "\r\n"
					  << req.headers() << req.body() << "\r\n";
		}

	private:
		request_method_t __method;
		headers_t		 __headers;
		string_t		 __path;
		http_version_t	 __http_version;
		body_t			 __body;
	};
} // namespace http
