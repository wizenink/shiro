#pragma once
#include <ostream>
namespace shiro {
	class vec3f {
	public:
		float x, y, z;
	public:
		vec3f();
		vec3f(float x, float y, float z);
		vec3f(const vec3f &v);
		friend vec3f operator+(const vec3f l, const vec3f &v);
		vec3f& operator+=(const vec3f &v);
		friend vec3f operator-(const vec3f l,const vec3f &v);
		vec3f& operator-=(const vec3f &v);
		friend vec3f operator*(const vec3f l, const float m);
		vec3f& operator*=(const float i);
		friend vec3f operator*(const vec3f l, const vec3f &v);
		vec3f& operator*=(const vec3f &v);
		friend vec3f operator/(const vec3f l, const float m);
		vec3f& operator/=(const float i);
		friend std::ostream& operator<<(std::ostream& out, const vec3f& v);
		float mod();

		static vec3f up();
		static vec3f down();
		static vec3f forward();
		static vec3f back();
		static vec3f left();
		static vec3f right();
		static vec3f one();
		static vec3f zero();


	};
}