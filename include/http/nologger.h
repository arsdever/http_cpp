#pragma once

#include <i_logger.h>

namespace http
{
	class nologger : public i_logger
	{
		virtual void log(log_level level, std::string const& message) override { }
		virtual void fatal(std::string const& message) override { }
		virtual void error(std::string const& message) override { }
		virtual void warning(std::string const& message) override { }
		virtual void info(std::string const& message) override { }
		virtual void detail(std::string const& message) override { }
		virtual void debug(std::string const& message) override { }
	};
} // namespace http