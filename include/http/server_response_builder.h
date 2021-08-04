#pragma once

#include <http/http_version.h>
#include <http/server_response.h>
#include <http/status_code.h>

namespace http
{
	class server_response_builder
	{
	public:
		using http_version_t = http_version;
		using status_code_t	 = status_code;
		using string_t		 = std::string;
		using headers_t		 = headers<response_header>;
		using body_t		 = string_t;

	public:
		server_response_builder& with_http_version(http_version_t const& v)
		{
			__http_version = v;
			return *this;
		}

		server_response_builder& with_status_code(status_code_t const& sc)
		{
			__status_code = sc;
			return *this;
		}

		server_response_builder& with_status_message(string_t const& sm)
		{
			__status_message = sm;
			return *this;
		}

		server_response_builder& with_header(response_header const& header)
		{
			__headers.add(header);
			return *this;
		}

		server_response_builder& with_body(string_t const& body)
		{
			__body = body;
			return *this;
		}

		server_response build() const
		{
			return server_response(__http_version, __status_code, __status_message, __headers, __body);
		}

	private:
		http_version_t __http_version;
		status_code_t  __status_code;
		string_t	   __status_message;
		headers_t	   __headers;
		body_t		   __body;
	};
} // namespace http