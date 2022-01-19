#pragma once

#include <boost/asio.hpp>
#include <boost/thread.hpp>

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

			__context		= new ::boost::asio::io_context();
			__work_guard	= new ::boost::asio::executor_work_guard(__context->get_executor());
			__worker_thread = new std::thread { [] { __context->run(); } };
		}

		static ::boost::asio::io_context& context()
		{
			init();
			return *__context;
		}

		static void terminate()
		{
			__context->stop();
			if (__worker_thread)
				__worker_thread->join();

			delete __work_guard;
			delete __context;
			delete __worker_thread;

			__context		= nullptr;
			__worker_thread = nullptr;
			__work_guard	= nullptr;
			__initialized	= false;
		}

	private:
		static bool																			 __initialized;
		static ::boost::asio::io_context*													 __context;
		static std::thread*																	 __worker_thread;
		static ::boost::asio::executor_work_guard<::boost::asio::io_context::executor_type>* __work_guard;
	};

	bool					   boost_static_context::__initialized = false;
	::boost::asio::io_context* boost_static_context::__context;
	std::thread*			   boost_static_context::__worker_thread = nullptr;
	::boost::asio::executor_work_guard<::boost::asio::io_context::executor_type>* boost_static_context::__work_guard =
		nullptr;
} // namespace http