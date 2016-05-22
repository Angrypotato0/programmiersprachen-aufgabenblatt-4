#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <iterator> 
#include <iostream>
#include "filter.hpp"
int RandomNumber () { return (std::rand()%101); }
bool is_even(unsigned int x){
	if (x%2 == 0){
		return true;
	}
	else{
		return false;
	}
}
bool is_odd(unsigned int x){
	if (x%2 != 0){
		return true;
	}
	else{
		return false;
	}
}
TEST_CASE("filter", "[Aufgabe11]") {
  std::vector<int> v(100);
  std::generate(std::begin(v),std::end(v),RandomNumber); 
  std::vector<int> alleven = filter(v, is_even);
  REQUIRE(std::all_of(alleven.begin(), alleven.end(), is_even));

  std::vector<int> b(100);
  std::generate(std::begin(b),std::end(b),RandomNumber);
  std::vector<int> allodd = filter(b, is_odd); 
  REQUIRE(std::all_of(allodd.begin(), allodd.end(), is_odd));
}

  


int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}