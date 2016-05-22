#ifndef VEC2_HPP
#define VEC2_HPP

class vec2
{
public:
	vec2();
	vec2(float a,float b);

	float a;
	float b;

	vec2& operator += (vec2 const& Vector1);
	vec2& operator -= (vec2 const& Vector1);
	vec2& operator *= (float Vector1);
	vec2& operator /= (float Vector1);
};
vec2 operator +(vec2 const& Vector2, vec2 const& Vector1);
vec2 operator -(vec2 const& Vector2, vec2 const& Vector1);
vec2 operator *(vec2 const& Vector1, float Sum);
vec2 operator /(vec2 const& Vector1, float Sum);
vec2 operator *(float Sum, vec2 const& Vector1);

#endif