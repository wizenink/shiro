#pragma once
#include <ostream>
namespace shiro {
	class vec4f {
	public:
		float x, y, z, w;
	public:
		vec4f();
		vec4f(float x, float y, float z, float w);
		vec4f(const vec4f &v);
		friend vec4f operator+(vec4f l,const vec4f &v);
		vec4f& operator+=(const vec4f &v);
		vec4f operator-(const vec4f &v);
		vec4f& operator-=(const vec4f &v);
		friend vec4f operator*(vec4f l, const float m);
		vec4f& operator*=(const vec4f &v);
		friend vec4f operator/(vec4f l, const float m);
		vec4f& operator/=(const vec4f &v);
		friend std::ostream& operator<<(std::ostream& out, const vec4f& v);
		float mod();
	};
}