#ifndef FILTER_HPP
#define FILTER_HPP
#include <vector>

template <typename Function, typename Container> 
  Container filter (Container const& c, Function const& f) {
  	Container result;

  	for (auto& i : c) {
  		if (f(i)) {
  			result.push_back(i);
  		}
  	}

    return result;
  }

#endif