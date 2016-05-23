#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iterator> 
#include "circle.hpp"

float RandomNumber () { return (std::rand()%101); } 
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

TEST_CASE("factorial", "[aufgabe3]"){
std::vector<unsigned int> v(100);
std::generate(std::begin(v),std::end(v),RandomNumber);
v.erase(std::remove_if(v.begin(),v.end(),is_odd),v.end());
std::copy(std::begin(v), std::end(v), std::ostream_iterator<unsigned int>(std::cout," | "));
std::cout<<std::endl;
REQUIRE(std::all_of(v.begin(),v.end(),is_even));
}

TEST_CASE("sortLambda", "[aufgabe9]") {
  std::vector<circle> c(10);

  for (int i=0; i<10; ++i) {
    c[i].set_radius(RandomNumber());
  }
  auto func = [](circle const& c1, circle const& c2) {return (c1 < c2);};
  std::sort(std::begin(c), std::end(c),func);

  REQUIRE(std::is_sorted(std::begin(c), std::end(c)));
}
TEST_CASE("describe_ContainerAdd", "[Aufgabe10]") {
  std::vector<int> v1 {1,2,3,4,5,6,7,8,9}; 
  std::vector<int> v2 {9,8,7,6,5,4,3,2,1}; 
  std::vector<int> v3 (9);

  std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),
    []  (int x, int y) { 
      return x + y; 
    }
  );

  REQUIRE(std::all_of(v3.begin(), v3.end(), 
    []  (int a) { 
      return a == 10; 
    })
  );
}

int main(int argc, char *argv[])
{
	
	return Catch::Session().run(argc,argv);
}