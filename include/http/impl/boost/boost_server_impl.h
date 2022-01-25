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

		~boost_server_impl() { stop(); }

		void start(unsigned short port)
		{
			// TODO: Implement better error handling
			error_code	  ec;
			tcp::endpoint ep { tcp::v4(), port };

			__acceptor.open(ep.protocol());
			__acceptor.bind(ep, ec);
			if (ec)
				{
					// An error has occurred. The server remains not started
					std::string msg = ec.message();
					__started		= false;
					return;
				}

			__acceptor.async_accept(
				std::bind(&boost_server_impl::handle_accept, this, std::placeholders::_1, std::placeholders::_2));

			__acceptor.listen(tcp::socket::max_listen_connections, ec);
			if (ec)
				{
					// An error has occurred. The server remains not started
					std::string msg = ec.message();
					__started		= false;
					return;
				}

			__started = true;
		}

		void stop()
		{
			__acceptor.close();
			__started = false;
		}

		bool started() const { return __started; }

		void on_peer_joined(std::function<void()> cb) { __on_peer_joined_cb = cb; }

	private:
		void handle_accept(error_code const& ec, tcp::socket s)
		{
			if (__on_peer_joined_cb)
				__on_peer_joined_cb();

			__acceptor.async_accept(
				std::bind(&boost_server_impl::handle_accept, this, std::placeholders::_1, std::placeholders::_2));
		}

	private:
		tcp::acceptor		  __acceptor;
		bool				  __started { false };
		std::function<void()> __on_peer_joined_cb;
	};
} // namespace http