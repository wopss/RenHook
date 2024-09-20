#pragma once

#include <system_error>
#include <utility>

#include <renhook/detail/core.hpp>
#include <renhook/errc.hpp>

namespace renhook
{
// TODO: https://www.foonathan.net/2016/05/final/
// TODO: Document this.
class RENHOOK_NODISCARD error_code
{
public:
    /**
     * @brief Constructs an error code with the default value and inner error.
     */
    error_code() noexcept;

    /**
     * @brief Constructs an error code with the specified value and the default inner error.
     *
     * @param[in] value The value of the error code.
     */
    error_code(errc value) noexcept;

    /**
     * @brief Constructs an error code with the specified value and inner error.
     *
     * @param[in] value         The value of the error code.
     * @param[in] inner_error   The inner error of the error code.
     */
    error_code(errc value, const std::error_code& inner_error) noexcept;

    /*error_code(const error_code&) noexcept = default;
    error_code(error_code&&) noexcept = default;

    error_code& operator=(const error_code&) noexcept = default;
    error_code& operator=(error_code&&) noexcept = default;

    ~error_code() noexcept = default;*/

    // error_code& operator=(errc rhs) noexcept;
    // error_code& operator=(std::pair<errc, std::error_code> rhs) noexcept;

    // void assign(errc value) noexcept;
    // void assign(errc value, const std::error_code& inner_error) noexcept;

    void clear() noexcept;

    RENHOOK_NODISCARD errc value() const noexcept;
    RENHOOK_NODISCARD const std::error_code& inner_error() const noexcept; // TODO: This might not be necessary.
    RENHOOK_NODISCARD std::string message() const;

    RENHOOK_NODISCARD explicit operator bool() const noexcept;

private:
    errc m_value;
    std::error_code m_inner_error;
};
} // namespace renhook

// bool operator==( const std::error_code& lhs, const std::error_code& rhs ) noexcept;
// bool operator!=( const std::error_code& lhs, const std::error_code& rhs ) noexcept;
// bool operator<( const std::error_code& lhs, const std::error_code& rhs ) noexcept;
// std::strong_ordering operator<=>( const std::error_code& lhs, const std::error_code& rhs ) noexcept;

// template< class CharT, class Traits >
// std::basic_ostream<CharT, Traits>& operator<<(basic_ostream<CharT, Traits>& os, const error_code& ec);
// template<> struct hash<error_code>;

// std::error_code make_error_code( std::errc e ) noexcept;
