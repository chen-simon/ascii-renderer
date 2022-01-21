#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/geometry.hpp"

TEST_CASE("Vector addition", "[vector_operations]")
{
    Vector3 v1(1, 1, 1);
    Vector3 v2(1, 2, 3);

    Vector3 actual(2, 3, 4);
    REQUIRE(v1 + v2 == actual);
}