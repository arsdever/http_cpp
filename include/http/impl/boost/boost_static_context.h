#pragma once

#include <boost/asio.hpp>

namespace http
{
	class boost_static_context
	{
	private:
		boost_static_context()							  = delete;
		boost_static_context(boost_static_context const&) = delete;
		boost_static_context(boost_static_context&&)	  = delete;
		boost_static_context operator=(boost_static_context const&) = delete;
		boost_static_context operator=(boost_static_context&&) = delete;

	public:
		static void init()
		{
			if (__initialized)
				return;

			__context = new ::boost::asio::io_context();
			__context->post([] {});
			__context->run();
		}

		static ::boost::asio::io_context& context()
		{
			init();
			return *__context;
		}

	private:
		static bool						  __initialized;
		static ::boost::asio::io_context* __context;
	};

	bool					   boost_static_context::__initialized = false;
	::boost::asio::io_context* boost_static_context::__context;
} // namespace http