#ifndef SWAP_HPP
#define SWAP_HPP
template <typename T1>
	void Swap (T1& x, T1& y){
		T1 temp = x;
		x = y;
		y = temp;
	}
#endif