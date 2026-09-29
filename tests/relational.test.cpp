// Copyright (c) Marcela Gallegos
// SPDX-License-Identifier: MIT

#include <catch2/catch_template_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>
#include <math3d/constants.hpp>
#include <math3d/relational.hpp>
#include <math3d/vec.hpp>

TEMPLATE_TEST_CASE("is_approx() scalar", "[relational][scalar]", float, double) {
    using T = TestType;
    constexpr T zero{0};
    constexpr auto eps = math3d::epsilon<T>;
    constexpr auto tol = eps * T{2};

    // TODO: Compile time evaluation

    SECTION("Within tolerance") {
        REQUIRE(math3d::is_approx(eps, eps, tol));
        REQUIRE(math3d::is_approx(zero, eps, tol));
        REQUIRE(math3d::is_approx(zero, -eps, tol));
        REQUIRE(math3d::is_approx(eps, zero, tol));
        REQUIRE(math3d::is_approx(-eps, zero, tol));
    }

    // TODO: Outside tolerance
    // TODO: Edge cases (NaN, inf)
}

TEMPLATE_PRODUCT_TEST_CASE(
    "is_approx() vector", "[relational][vector]", (math3d::tvec2, math3d::tvec3, math3d::tvec4), (float, double)
) {
    using T = typename TestType::value_type;
    constexpr auto tol = math3d::epsilon<T>;
    constexpr TestType v1{0};
    constexpr TestType v2{1};

    // TODO: Compile time evaluation

    REQUIRE(math3d::is_approx(v1, v1, tol));
    REQUIRE_FALSE(math3d::is_approx(v1, v2, tol));
}
