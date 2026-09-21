// Copyright (c) Marcela Gallegos
// SPDX-License-Identifier: MIT

#ifndef MATH3D_DETAIL_TVEC_STORAGE_HPP
#define MATH3D_DETAIL_TVEC_STORAGE_HPP

namespace math3d::detail {

template <typename T, int N, bool Aligned>
struct tvec_storage {
    T data[N];
};

template <typename T, bool Aligned>
struct alignas(Aligned ? sizeof(T) * 2 : alignof(T)) tvec_storage<T, 2, Aligned> {
    union {
        T data[2];
        struct {
            T x;
            T y;
        };
        struct {
            T u;
            T v;
        };
    };
};

template <typename T, bool Aligned>
struct alignas(Aligned ? (sizeof(T) * 4) : alignof(T)) tvec_storage<T, 3, Aligned> {
    union {
        T data[3];
        struct {
            T x;
            T y;
            T z;
        };
        struct {
            T r;
            T g;
            T b;
        };
    };
};

template <typename T, bool Aligned>
struct alignas(Aligned ? (sizeof(T) * 4) : alignof(T)) tvec_storage<T, 4, Aligned> {
    union {
        T data[4];
        struct {
            T x;
            T y;
            T z;
            T w;
        };
        struct {
            T r;
            T g;
            T b;
            T a;
        };
    };
};

} // namespace math3d::detail

#endif // MATH3D_DETAIL_TVEC_STORAGE_HPP
