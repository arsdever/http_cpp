#pragma once

#include <http/request_header.h>
#include <http/request_method.h>
#include <http/server_request.h>

namespace http
{
	class server_request_builder
	{
	public:
		using request_method_t = request_method;
		using http_version_t   = http_version;
		using headers_t		   = headers<request_header>;
		using string_t		   = std::string;
		using body_t		   = std::string;

	public:
		server_request_builder() { }
		server_request_builder(server_request_builder const& o) { }
		server_request_builder(server_request_builder&& o) { }

		server_request_builder& with_method(request_method_t const& m)
		{
			__method = m;
			return *this;
		}

		server_request_builder& with_header(request_header const& h)
		{
			__headers.add(h);
			return *this;
		}

		server_request_builder& with_path(string_t const& p)
		{
			__path = p;
			return *this;
		}

		server_request_builder& with_http_version(http_version_t const& hv)
		{
			__http_version = hv;
			return *this;
		}

		server_request_builder& with_body(body_t const& b)
		{
			__body = b;
			return *this;
		}

		server_request build() { return server_request(__method, __path, __http_version, __headers, __body); }

	private:
		request_method_t __method;
		headers_t		 __headers;
		string_t		 __path;
		http_version_t	 __http_version;
		body_t			 __body;
	};
} // namespace http
