// Copyright (c) Marcela Gallegos
// SPDX-License-Identifier: MIT

#ifndef MATH3D_VEC_HPP
#define MATH3D_VEC_HPP

#include "tvec.hpp"

namespace math3d {

template <typename T> using tvec2 = tvec<T, 2, true>;
template <typename T> using tvec3 = tvec<T, 3>;
template <typename T> using aligned_tvec3 = tvec<T, 3, true>;
template <typename T> using tvec4 = tvec<T, 4, true>;

using vec2 = tvec2<float>;
using dvec2 = tvec2<double>;
using ivec2 = tvec2<int>;
using uvec2 = tvec2<unsigned>;

using vec3 = tvec3<float>;
using dvec3 = tvec3<double>;
using ivec3 = tvec3<int>;
using uvec3 = tvec3<unsigned>;

using aligned_vec3 = aligned_tvec3<float>;
using aligned_dvec3 = aligned_tvec3<double>;
using aligned_ivec3 = aligned_tvec3<int>;
using aligned_uvec3 = aligned_tvec3<unsigned>;

using vec4 = tvec4<float>;
using dvec4 = tvec4<double>;
using ivec4 = tvec4<int>;
using uvec4 = tvec4<unsigned>;

} // namespace math3d

#endif // MATH3D_VEC_HPP
