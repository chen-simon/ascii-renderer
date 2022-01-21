#define CONFIG_CATCH_MAIN
#include "catch.hpp"

#include "geometry.hpp"

TEST_CASE("Vector addition")
{
    Vector3 v1(1, 1, 1);
    Vector3 v2(1, 2, 3);


    Vector3 actual(2, 4, 5);
    REQUIRE(v1 + v2 == actual);
}