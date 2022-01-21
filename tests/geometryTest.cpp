#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/geometry.hpp"

TEST_CASE("Vector addition", "[vector_operations]")
{
    Vector3 v1(1, 1, 1);
    Vector3 v2(1, 2, 3);

    Vector3 expected(2, 3, 4);
    REQUIRE(v1 + v2 == expected);
}

TEST_CASE("Vector multiplication", "[vector_operations]")
{
    Vector3 v1(1, 1, 1);
    double scalar = 1.5;

    Vector3 expected(1.5, 1.5, 1.5);
    REQUIRE(scalar * v1 == expected);
}

TEST_CASE("Vector subtraction", "[vector_operations]")
{
    Vector3 v1(1, 1, 1);
    Vector3 v2(1, 2, 3);

    Vector3 expected(0, -1, -2);
    REQUIRE(v1 - v2 == expected);
}

TEST_CASE("Vector dot product", "[vector_operations]")
{
    Vector3 v1(4, 0, 5);
    Vector3 v2(1, 2, 3);

    double expected = 19;
    REQUIRE(v1 * v2 == expected);
}

