#pragma once

#include <boost/asio.hpp>
#include <http/impl/boost/boost_server_impl.h>
#include <http/server.h>

namespace http
{
	struct boost
	{
		using server_impl_t = boost_server_impl;
	};

	using boost_server = server<boost>;
} // namespace http