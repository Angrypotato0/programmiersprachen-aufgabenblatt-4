#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
int RandomNumber () { return (std::rand()%101); }
int main()
{
    
	std::list<int> l1(100);
	std::generate(std::begin(l1),std::end(l1),RandomNumber);
	std::vector<int> v(l1.size());
	std::copy(std::begin(l1), std::end(l1),std::begin(v));
	std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout,"\n"));
	return 0;
}