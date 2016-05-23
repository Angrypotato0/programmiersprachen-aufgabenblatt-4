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
	friend bool operator==(circle const& lhs, circle const& rhs);
	friend bool operator<(circle const& lhs, circle const& rhs);
	friend bool operator>(circle const& lhs, circle const& rhs);

	
	

private:
	
	 
	float r; 
	 

};

#endif 