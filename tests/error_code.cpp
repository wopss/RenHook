#include <renhook/error_code.hpp>

#include <catch2/catch_test_macros.hpp>

#include <Windows.h>

TEST_CASE("an error code should have its value set to 'success' when using the default constructor", "[error_code]")
{
    renhook::error_code err;
    REQUIRE(err.value() == renhook::errc::success);
}

TEST_CASE("an error code should have its inner error empty when using the default constructor", "[error_code]")
{
    renhook::error_code err;
    REQUIRE_FALSE(err.inner_error());
}

TEST_CASE("an error code should have its value set to a custom error when using the 'error_code(errc)' constructor",
          "[error_code]")
{
    renhook::error_code err(renhook::errc::error_name);
    REQUIRE(err.value() == renhook::errc::error_name);
}

TEST_CASE("an error code should have its inner error empty when using 'error_code(errc)' constructor", "[error_code]")
{
    renhook::error_code err(renhook::errc::error_name);
    REQUIRE_FALSE(err.inner_error());
}

// TODO: Fill other things here.

TEST_CASE("an error code should replace its error code with the default value when calling 'clear' function",
          "[error_code]")
{
    renhook::error_code err(renhook::errc::error_name);
    err.clear();

    REQUIRE(err.value() == renhook::errc::success);
}

TEST_CASE("an error code should replace its inner error with the default value when calling 'clear' function",
          "[error_code]")
{
    renhook::error_code err(renhook::errc::error_name, std::error_code(ERROR_NETWORK_BUSY, std::generic_category()));
    err.clear();

    REQUIRE_FALSE(err.inner_error());
}

TEST_CASE("an error code should return the current error code when calling 'value' function", "[error_code]")
{
    renhook::error_code err(renhook::errc::error_name);
    REQUIRE(err.value() == renhook::errc::error_name);
}

TEST_CASE("an error code should return the inner error when calling 'inner_error' function", "[error_code]")
{
    auto windows_err = std::error_code(ERROR_NETWORK_BUSY, std::generic_category());

    renhook::error_code err(renhook::errc::error_name, windows_err);
    REQUIRE(err.inner_error() == windows_err);
}

// TODO: Think more about these below.

TEST_CASE("an error code should return 'false' when casting it to boolean using 'errc::success'", "[error_code]")
{
    renhook::error_code err;
    REQUIRE_FALSE(err);
}

TEST_CASE("an error code should return 'true' when casting it to boolean using an error code", "[error_code]")
{
    renhook::error_code err(renhook::errc::error_name);
    REQUIRE(err);
}

TEST_CASE("an error code should return 'true' when casting it to boolean using an error code and an inner error",
          "[error_code]")
{
    renhook::error_code err(renhook::errc::error_name, std::error_code(ERROR_NETWORK_BUSY, std::generic_category()));
    REQUIRE(err);
}
