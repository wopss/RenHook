# Coding Guidelines

This document contains the coding guidelines of this library. Any contributor
should follow this guidelines.

## C++ version

This library is mainly targeting C++14, i.e., newer C++ standards can be used
with macros providing a fallback to the targeted version.

> :warning: **GOOD**
> ```cpp
> #if RENHOOK_HAS_CPP17_ATTRIBUTE(nodiscard)
> #define RENHOOK_NODISCARD [[nodiscard]]
> #else
> #define RENHOOK_NODISCARD
> #endif
> ```






All functions marked as const and noexcept by default, remove them if necessary.
All class marked as final by default, remove them if necessary.
All functions must be constexpr by default, remove if the function will not do constexpr stuff.
