// Copyright (c) Marcela Gallegos
// SPDX-License-Identifier: MIT

#ifndef MATH3D_RELATIONAL_HPP
#define MATH3D_RELATIONAL_HPP

#include "tvec.hpp"
#include <concepts>

namespace math3d {

template <std::floating_point T>
[[nodiscard]] constexpr bool is_approx(T a, T b, T tol) noexcept {
    T abs_diff = a > b ? a - b : b - a;
    return abs_diff <= tol;
}

template <std::floating_point T, int N, bool Aligned>
[[nodiscard]] constexpr bool is_approx(tvec<T, N, Aligned> a, tvec<T, N, Aligned> b, T tol) noexcept {
    bool is_equal = true;

    for (int i = 0; i < N; ++i) {
        is_equal &= is_approx(a[i], b[i], tol);
    }

    return is_equal;
}

} // namespace math3d

#endif // MATH3D_RELATIONAL_HPP
