#pragma once

namespace http
{
	template <typename header_t>
	class headers
	{
	public:
		headers() : __map {} { }
		headers(headers const& o) : __map { o.__map } { }
		headers(headers&& o) : __map { o.__map } { }

		void add(header_t const& header)
		{
			std::string key = header.key();
			// key				= std::move(utilities::string_manip::to_lower(key));
			// std::replace(key.begin(), key.end(), '-', '_');
			__map.insert({ key, header });
		}

		bool has(std::string const& key) const { return __map.contains(key); }

		header_t operator[](std::string const& key_string) { return __map[ key_string ]; }

		header_t operator[](std::string const& key_string) const { return __map.find(key_string)->second; }

		header_t operator[](header_t::known_header_enum key)
		{
			return operator[](header_t::header_key_to_string(key));
		}

		header_t operator[](header_t::known_header_enum key) const
		{
			return operator[](header_t::header_key_to_string(key));
		}

		header_t operator[](int key)
		{
			return operator[](static_cast<header_t::known_header_enum>(key));
		}

		header_t operator[](int key) const
		{
			return operator[](static_cast<header_t::known_header_enum>(key));
		}

		size_t count() const { return __map.size(); }

	private:
		std::unordered_map<std::string, header_t> __map;
	};
} // namespace http