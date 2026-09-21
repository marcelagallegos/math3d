// Copyright (c) Marcela Gallegos
// SPDX-License-Identifier: MIT

#ifndef MATH3D_DETAIL_CONCEPTS_HPP
#define MATH3D_DETAIL_CONCEPTS_HPP

#include <concepts>

namespace math3d::detail {

// clang-format off
template <typename T>
concept scalar = (std::integral<T> || std::floating_point<T>) &&
                 !std::same_as<T, bool> &&
                 !std::same_as<T, char> &&
                 !std::same_as<T, wchar_t> &&
                 !std::same_as<T, char8_t> &&
                 !std::same_as<T, char16_t> &&
                 !std::same_as<T, char32_t>;
// clang-format on

} // namespace math3d::detail

#endif // MATH3D_DETAIL_CONCEPTS_HPP
