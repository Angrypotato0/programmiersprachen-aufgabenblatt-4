#include "vec2.hpp"
#include <iostream>

vec2::vec2():
a{0}, b{0}{}

vec2::vec2(float a_, float b_):
a{a_}, b{b_}{}

vec2& vec2::operator +=(vec2 const& Vector1){
	a += Vector1.a;
	b += Vector1.b;

	return *this;
}

vec2& vec2::operator -=(vec2 const& Vector1){
	a -= Vector1.a;
	b -= Vector1.b;

	return *this;
}

vec2& vec2::operator *=(float Vector1){
	a *= Vector1;
	b *= Vector1;

	return *this;
}

vec2& vec2::operator /=(float Vector1){
	if (Vector1 == 0.0f){
		std::cout <<"!! NICHT DURCH 0 TEILBAR !!"<< std::endl; 
	}
		else {
			a /= Vector1;
			b /= Vector1;
			return *this;

		}
}

vec2 operator +(vec2 const& Vector2, vec2 const& Vector1){
return vec2 {Vector1.a + Vector2.a, Vector1.b + Vector2.b};
}

vec2 operator -(vec2 const& Vector2, vec2 const& Vector1){
return vec2 {Vector2.a - Vector1.a, Vector2.b - Vector1.b};
}

vec2 operator *(vec2 const& Vector1, float Sum ){
return vec2 {Vector1.a * Sum, Vector1.b * Sum};
}

vec2 operator *(float Sum, vec2 const& Vector1){
return vec2 {Sum * Vector1.a, Sum * Vector1.b};
}

vec2 operator /(vec2 const& Vector1, float Sum) { 
	if (Sum == 0.0f) {
		std::cout <<"!! NICHT DURCH 0 TEILBAR !!"<< std::endl;
	}
	
	else {
		return vec2 {Vector1.a / Sum, Vector1.b / Sum};
	}
}


