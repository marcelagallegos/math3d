// Copyright (c) Marcela Gallegos
// SPDX-License-Identifier: MIT

#ifndef MATH3D_GEOMETRIC_HPP
#define MATH3D_GEOMETRIC_HPP

#include "tvec.hpp"
#include <cmath>

namespace math3d {

template <typename T, int N, bool Aligned>
[[nodiscard]] constexpr T dot(tvec<T, N, Aligned> a, tvec<T, N, Aligned> b) noexcept {
    T sum = static_cast<T>(0);
    for (int i = 0; i < N; ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}

// clang-format off
template <typename T, bool Aligned>
[[nodiscard]] constexpr tvec<T, 3, Aligned> cross(tvec<T, 3, Aligned> a, tvec<T, 3, Aligned> b) noexcept {
    return {
        a[1] * b[2] - b[1] * a[2], 
        a[2] * b[0] - a[0] * b[2], 
        a[0] * b[1] - b[0] * a[1]
    };
}
// clang-format on

template <typename T, int N, bool Aligned>
[[nodiscard]] constexpr T length_sq(tvec<T, N, Aligned> v) noexcept {
    return dot(v, v);
}

template <typename T, int N, bool Aligned>
    requires std::floating_point<T>
[[nodiscard]] T length(tvec<T, N, Aligned> v) noexcept {
    return std::sqrt(length_sq(v));
}

template <typename T, int N, bool Aligned>
    requires std::floating_point<T>
[[nodiscard]] tvec<T, N, Aligned> normalize(tvec<T, N, Aligned> v) noexcept {
    return v * (static_cast<T>(1) / length(v));
}

} // namespace math3d

#endif // MATH3D_GEOMETRIC_HPP
