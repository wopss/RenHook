#pragma once

#include <cstdint>

namespace renhook
{
// TODO: Document this.
enum class RENHOOK_NODISCARD errc : std::uint8_t
{
    success = 0,
    error_name
};
} // namespace renhook
