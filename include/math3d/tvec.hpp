// Copyright (c) Marcela Gallegos
// SPDX-License-Identifier: MIT

#ifndef MATH3D_TVEC_HPP
#define MATH3D_TVEC_HPP

#include "detail/concepts.hpp"
#include "detail/tvec_storage.hpp"
#include <cassert>
#include <concepts>
#include <type_traits>

namespace math3d {

template <typename T, int N, bool Aligned = false>
    requires(math3d::detail::scalar<T> && N >= 2 && N <= 4)
struct tvec : public detail::tvec_storage<T, N, Aligned> {

    constexpr tvec() noexcept = default;

    explicit constexpr tvec(T s) noexcept : detail::tvec_storage<T, N, Aligned>{} {
        for (int i = 0; i < N; ++i) {
            this->data[i] = s;
        }
    }

    template <typename... Args>
        requires(sizeof...(Args) == N && (std::convertible_to<Args, T> && ...))
    constexpr tvec(Args... args) noexcept : detail::tvec_storage<T, N, Aligned>{{static_cast<T>(args)...}} {}

    // TODO: conversion constructors

    [[nodiscard]] constexpr T& operator[](int i) noexcept {
        assert(i >= 0 && i < N && "tvec index out of bounds");
        return this->data[i];
    }

    [[nodiscard]] constexpr const T& operator[](int i) const noexcept {
        assert(i >= 0 && i < N && "tvec index out of bounds");
        return this->data[i];
    }

    [[nodiscard]] constexpr tvec operator-() const noexcept
        requires std::is_signed_v<T>
    {
        tvec result{};
        for (int i = 0; i < N; ++i) {
            result.data[i] = -this->data[i];
        }
        return result;
    }

    constexpr tvec& operator+=(tvec v) noexcept {
        for (int i = 0; i < N; ++i) {
            this->data[i] += v.data[i];
        }
        return *this;
    }

    constexpr tvec& operator-=(tvec v) noexcept {
        for (int i = 0; i < N; ++i) {
            this->data[i] -= v.data[i];
        }
        return *this;
    }

    constexpr tvec& operator*=(T s) noexcept {
        for (int i = 0; i < N; ++i) {
            this->data[i] *= s;
        }
        return *this;
    }

    constexpr tvec& operator/=(T s) noexcept {
        if constexpr (std::floating_point<T>) {
            return *this *= (static_cast<T>(1) / s);
        } else {
            for (int i = 0; i < N; ++i) {
                this->data[i] /= s;
            }
            return *this;
        }
    }

    [[nodiscard]] friend constexpr tvec operator+(tvec lhs, tvec rhs) noexcept { return lhs += rhs; }
    [[nodiscard]] friend constexpr tvec operator-(tvec lhs, tvec rhs) noexcept { return lhs -= rhs; }
    [[nodiscard]] friend constexpr tvec operator*(tvec v, T s) noexcept { return v *= s; }
    [[nodiscard]] friend constexpr tvec operator*(T s, tvec v) noexcept { return v *= s; }
    [[nodiscard]] friend constexpr tvec operator/(tvec v, T s) noexcept { return v /= s; }

    [[nodiscard]] friend constexpr bool operator==(tvec a, tvec b) noexcept {
        for (int i = 0; i < N; ++i) {
            if (a.data[i] != b.data[i])
                return false;
        }
        return true;
    }

    // TODO: fuzzy matching
};

} // namespace math3d

#endif // MATH3D_TVEC_HPP
