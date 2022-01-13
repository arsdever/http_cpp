#pragma once

#include <http/response_builder.h>
#include <http/response_parser.h>
#include <http/standards/rfc2616_response_builder_impl.h>
#include <http/standards/rfc2616_response_parser_impl.h>

namespace http
{
	class rfc2616_response_parser_impl;
	class rfc2616_response_builder_impl;

	class rfc2616
	{
	public:
		using response_parser_impl_t  = rfc2616_response_parser_impl;
		using response_builder_impl_t = rfc2616_response_builder_impl;
	};

	using rfc2616_response_parser  = response_parser<rfc2616>;
	using rfc2616_response_builder = response_builder<rfc2616>;
} // namespace http