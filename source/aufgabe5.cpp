#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iterator> 

unsigned int RandomNumber () { return (std::rand()%101); }
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

TEST_CASE("describe_factorial", "[aufgabe3]"){
std::vector<unsigned int> v(100);
std::generate(std::begin(v),std::end(v),RandomNumber);
v.erase(std::remove_if(v.begin(),v.end(),is_odd),v.end());
std::copy(std::begin(v), std::end(v), std::ostream_iterator<unsigned int>(std::cout," | "));
std::cout<<std::endl;
REQUIRE(std::all_of(v.begin(),v.end(),is_even));
}
int main(int argc, char *argv[])
{
	
	return Catch::Session().run(argc,argv);
}