#pragma once

#include <http/response_builder.h>
#include <http/response_parser_exception.h>

namespace http
{
	template <typename standard_t>
	class response_parser
	{
	public:
		using parser_t	= standard_t::response_parser_impl_t;
		using builder_t = standard_t::response_builder_impl_t;

	public:
		response_parser() : __impl {} { }

		template <typename iterator_t>
		void parse(iterator_t const& dbegin, iterator_t const& dend)
		{
			__impl.parse<iterator_t>(dbegin, dend);
		}

		builder_t builder() const { return __impl.builder(); }

	private:
		template <typename iterator_t>
		void parse_headers(iterator_t& tb, iterator_t const& dend)
		{
			__impl.parse_headers<iterator_t>(tb, dend);
		}

		template <typename iterator_t>
		http_version http_version_from_string(iterator_t const& b, iterator_t const& e)
		{
			return __impl.http_version_from_string<iterator_t>(b, e);
		}

		template <typename iterator_t>
		status_code status_code_from_string(iterator_t const& b, iterator_t const& e)
		{
			return __impl.status_code_from_string<iterator_t>(b, e);
		}

	private:
		parser_t __impl;
	};
} // namespace http