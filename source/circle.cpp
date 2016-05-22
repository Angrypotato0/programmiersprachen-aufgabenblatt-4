#include <iostream>
#include "circle.hpp"

	
circle::circle(): 
 r {1.0f} {

}
	
	
circle::circle( float r_ ): 
 r {r_} {

	if (r_ == 0.0f) {
		std::cout << "!! Der Radius muss groeßer Null sein !!" << std::endl;
		r = 1.0f; 
	}

	else if (r_ < 0.0f) {
		std::cout <<"!! Sie habe einen negativen Radius angegeben. Nicht Schlimm ;)"<<std::endl;
		r = r_ * (-1);
	}
}

	
float circle::get_diameter() const {
	return 2 * r;
}

	 
float circle::get_area() const {
	return M_PI * r * r;
}

	
float circle::get_circumference() const {
	return 2 * M_PI * r;
}

	
void circle::set_radius(float r_) {
	if (r_ == 0.0f) {
		std::cout << "!! Der Radius muss groeßer Null sein !!" << std::endl;
		r = 1.0f; 
	}

	else if (r_ < 0.0f) {
		std::cout <<"!! Sie habe einen negativen Radius angegeben. Nicht Schlimm ;)"<<std::endl;
		r = r_ * (-1);
	}

	else r = r_;
}

	 
float circle::get_radius() const {
	return r;
}
	
	

bool circle::operator == (circle const& x) const {
	return r == x.r;
}

	
bool circle::operator < (circle const& x) const {
	return r < x.r;
}


bool circle::operator > (circle const& x) const {
	return r > x.r;
} 
	


	 
