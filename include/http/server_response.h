#pragma once

#include <http/headers.h>
#include <http/http_version.h>
#include <http/response_header.h>
#include <http/status_code.h>
#include <http/utilities/string_manip.h>

namespace http
{
	class server_response
	{
	public:
		using http_version_t = http_version;
		using status_code_t	 = status_code;
		using string_t		 = std::string;
		using headers_t		 = headers<response_header>;
		using body_t		 = string_t;

	public:
		server_response()
			: __http_version { http_version_t::unknown }, __status_code { status_code_t::sc_ok },
			  __status_message {}, __headers {}, __body {}
		{
		}

		server_response(http_version_t ver, status_code_t sc, string_t sm, headers_t hs, body_t b)
			: __http_version { ver }, __status_code { sc }, __status_message { sm }, __headers { hs }, __body { b }
		{
		}

		inline http_version_t http_version() const { return __http_version; }
		inline status_code_t  status_code() const { return __status_code; }
		inline string_t		  status_message() const { return __status_message; }
		inline headers_t	  headers() const { return __headers; }
		inline body_t		  body() const { return __body; }

		inline size_t content_length() const
		{
			return __headers.has("Content-Length") ? std::stoi(__headers[ "Content-Length" ].value())
												   : static_cast<size_t>(-1);
		}

	private:
		http_version_t __http_version;
		status_code_t  __status_code;
		string_t	   __status_message;
		headers_t	   __headers;
		body_t		   __body;
	};
} // namespace http