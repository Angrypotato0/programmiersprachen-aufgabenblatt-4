#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <iterator> 
#include <iostream>
#include "circle.hpp"
#include "swap.hpp"
TEST_CASE("Template_swap", "[aufgabe8]") {
  int i1 = 42;
  int i2 = 14;

  Swap(i1, i2);
  REQUIRE(i1 == 14);
  REQUIRE(i2 == 42);

  double d1 = 9.9;
  double d2 = 9.1;

  Swap(d1, d2);
  REQUIRE(d1 == 9.1);
  REQUIRE(d2 == 9.9);

  circle a {11.0f};
  circle b {9.01f};

  Swap(a, b);
  REQUIRE(a == 9.01f);
  REQUIRE(b == 11.0f);

  char c1 = 'b';
  char c2 = 'a';

  Swap(c1, c2);
  REQUIRE(c1 == 'a');
  REQUIRE(c2 == 'b');


}

int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}