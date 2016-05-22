#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iterator> 
#include "circle.hpp"
#include <list>

TEST_CASE("Circle_Order", "[aufgabe7]"){
std::vector<circle> lC(6);
int j;
circle temp;
lC[0]= { 3.2};
lC[1]= { 4.2};
lC[2]= { 6.9};
lC[3]= { 7.0};
lC[4]= { 5.2};
lC[5]= { 1.2};
for (unsigned int i=0;i < lC.size();i++){
	j=i;
	while(j>0 && lC[j]<lC[j-1]){
		temp = lC[j];
		lC[j]=lC[j-1];
		lC[j-1]=temp;
		j--;
	}
}
REQUIRE ( std :: is_sorted ( lC. begin () , lC. end ()));




}
int main(int argc, char *argv[])
{
	
	return Catch::Session().run(argc,argv);
}