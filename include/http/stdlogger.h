#pragma once

#include <i_logger.h>

namespace http
{
	class stdlogger : public i_logger
	{
		virtual void log(log_level level, std::string const& message) override
		{
			switch (level)
				{
				case log_level::fatal: fatal(message); return;
				case log_level::error: error(message); return;
				case log_level::warning: warning(message); return;
				case log_level::info: info(message); return;
				case log_level::detail: detail(message); return;
				case log_level::debug: debug(message); return;
				}
		}
		virtual void fatal(std::string const& message) override { std::cout << "[fatal] " << message << std::endl; }
		virtual void error(std::string const& message) override { std::cout << "[error] " << message << std::endl; }
		virtual void warning(std::string const& message) override
		{
			std::cout << "[warning] " << message << std::endl;
		}
		virtual void info(std::string const& message) override { std::cout << "[info] " << message << std::endl; }
		virtual void detail(std::string const& message) override { std::cout << "[detail] " << message << std::endl; }
		virtual void debug(std::string const& message) override { std::cout << "[debug] " << message << std::endl; }
	};
} // namespace http