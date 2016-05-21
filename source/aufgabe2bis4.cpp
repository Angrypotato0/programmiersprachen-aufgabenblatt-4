#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <map>
int RandomNumber () { return (std::rand()%101); }
int main()
{
    
	std::list<unsigned int> l1(100);
	std::generate(std::begin(l1),std::end(l1),RandomNumber);
	std::vector<unsigned int> v(l1.size());
	std::copy(std::begin(l1), std::end(l1),std::begin(v));
	std::copy(std::begin(v), std::end(v), std::ostream_iterator<unsigned int>(std::cout," | "));
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Die Liste beschteht aus "<<l1.size()<<" elementen."<<std::endl;
	std::cout<<std::endl;
	std::set<unsigned int> slist(std::begin(l1),std::end(l1));
	std::cout << "Diese Zahlen haben es leider nicht in die Liste geschaft (Doffes standart RAND) : "<<std::endl;
	for (unsigned int i = 0; i<=100; ++i ){
		if (slist.count(i) != true){
			std::cout<< i << " | ";
		}
	}
	std::cout<<std::endl;
	std::map<unsigned int, unsigned int> mliste;
    for (std::list<unsigned int>::iterator i = l1.begin(); i != l1.end(); ++i) {
    ++mliste[*i];
  	}
    std::cout<<std::endl;
  	std::cout << "Uuuund sooooo haeufig sind alle vorgekommen :" << std::endl;
  	for (int i = 0; i <= 100; ++i) {
    	std::cout << i << " : " << mliste[i] << " | ";
	}
	return 0;
}