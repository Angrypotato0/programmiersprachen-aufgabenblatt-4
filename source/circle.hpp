#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <cmath>

class circle {
public: 
	
	circle();
	circle(float r );

	
	
	float get_diameter() const;
	float get_area() const; 
	float get_circumference() const;
	void set_radius(float r_); 
	float get_radius() const; 
	bool operator == (circle const& x) const;
	bool operator < (circle const& x) const;
	bool operator > (circle const& x) const;

	
	

private:
	
	 
	float r; 
	 

};

#endif 