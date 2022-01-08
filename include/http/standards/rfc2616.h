#pragma once

#include <http/response_parser.h>
#include <http/standards/rfc2616_response_parser_impl.h>

namespace http
{
	class rfc2616_response_parser_impl;

	struct rfc2616
	{
		using parser_t = rfc2616_response_parser_impl;
	};

	using rfc2616_response_parser = response_parser<rfc2616>;
} // namespace http