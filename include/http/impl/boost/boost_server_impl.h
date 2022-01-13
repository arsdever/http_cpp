#pragma once

#include <http/impl/boost/boost_static_context.h>

using ::boost::asio::ip::tcp;
using ::boost::system::error_code;

namespace http
{
	class boost_server_impl
	{
	public:
		boost_server_impl() : __acceptor(boost_static_context::context()) { }

		void start(unsigned short port)
		{
			// TODO: Implement better error handling
			error_code ec;
			__acceptor.bind(tcp::endpoint { tcp::v4(), port }, ec);
			if (!ec)
				{
					// An error has occurred. The server remains not started
					__started = false;
					return;
				}

			__acceptor.async_accept(
				std::bind(&boost_server_impl::handle_accept, this, std::placeholders::_1, std::placeholders::_2));

			__acceptor.listen(tcp::socket::max_listen_connections, ec);
			if (!ec)
				{
					// An error has occurred. The server remains not started
					__started = false;
					return;
				}

			__started = true;
		}

		bool started() const { return __started; }

	private:
		void handle_accept(error_code const& ec, tcp::socket s) { }

	private:
		tcp::acceptor __acceptor;
		bool		  __started { false };
	};
} // namespace http