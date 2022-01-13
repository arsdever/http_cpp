#pragma once

#include <http/http_version.h>
#include <http/server_response.h>
#include <http/status_code.h>

namespace http
{
	template <typename standard_t>
	class response_builder
	{
	public:
		using string_t		 = std::string;
		using http_version_t = http_version;
		using status_code_t	 = status_code;
		using headers_t		 = headers<response_header>;
		using body_t		 = string_t;
		using impl_t		 = standard_t::response_builder_impl_t;

	public:
		response_builder<standard_t>& with_http_version(http_version_t const& v)
		{
			__impl.with_http_version(v);
			return *this;
		}

		response_builder<standard_t>& with_status_code(status_code_t const& sc)
		{
			__impl.with_status_code(sc);
			return *this;
		}

		response_builder<standard_t>& with_status_message(string_t const& sm)
		{
			__impl.with_status_message(sm);
			return *this;
		}

		response_builder<standard_t>& with_header(response_header const& header)
		{
			__impl.with_header(header);
			return *this;
		}

		response_builder<standard_t>& with_body(string_t const& body)
		{
			__impl.with_body(body);
			return *this;
		}

		server_response build() const { return __impl.build(); }

	private:
		impl_t __impl;
	};
} // namespace http