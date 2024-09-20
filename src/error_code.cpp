#include <renhook/error_code.hpp>

renhook::error_code::error_code() noexcept
    : error_code(errc::success)
{
}

renhook::error_code::error_code(errc value) noexcept
    : error_code(value, {})
{
}

renhook::error_code::error_code(errc value, const std::error_code& inner_error) noexcept
    : m_value(value)
    , m_inner_error(inner_error)
{
    // TODO: Test this.
    // TODO: See if const ref is better. https://learn.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/cpp-value-categories
}

void renhook::error_code::clear() noexcept
{
    m_value = errc::success;
    m_inner_error.clear();
}

renhook::errc renhook::error_code::value() const noexcept
{
    return m_value;
}

const std::error_code& renhook::error_code::inner_error() const noexcept
{
    return m_inner_error;
}

std::string renhook::error_code::message() const
{
    return std::string();
}

renhook::error_code::operator bool() const noexcept
{
    // TODO: Maybe assert if value = success && !inner_error.
    return value() != errc::success || m_inner_error;
}
