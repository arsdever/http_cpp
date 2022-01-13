#pragma once

namespace http
{
	template <typename backend_t>
	class server
	{
	public:
		using impl_t = backend_t::server_impl_t;

	public:
		void start(unsigned short port) { __backend.start(port); }

		bool started() { return __backend.started(); }

	private:
		impl_t __backend;
	};
} // namespace http
