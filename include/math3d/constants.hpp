// Copyright (c) Marcela Gallegos
// SPDX-License-Identifier: MIT

#ifndef MATH3D_CONSTANTS_HPP
#define MATH3D_CONSTANTS_HPP

#include <concepts>
#include <limits>

namespace math3d {

template <std::floating_point T>
constexpr T epsilon = std::numeric_limits<T>::epsilon();

} // namespace math3d

#endif // MATH3D_CONSTANTS_HPP
