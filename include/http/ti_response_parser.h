#pragma once

namespace http
{
	template <typename impl_t>
	class ti_response_parser
	{
	public:
		template <typename iterator_t>
		void parse(iterator_t b, iterator_t e)
		{
			__impl.parse(b, e);
		}

		impl_t::builder_t builder()
		{
			return __impl.builder();
		}

	private:
		impl_t __impl;
	};
} // namespace http