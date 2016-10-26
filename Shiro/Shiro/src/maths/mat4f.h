#pragma once
#include <ostream>
#include <vector>
#define MAX_ELEMENTS 16
#define RANGO 4
namespace shiro {
	class mat4f {
	public:
		float elements[MAX_ELEMENTS];
	public:
		mat4f();
		mat4f(const std::vector<float> & v);
		mat4f(const mat4f & v);
		friend mat4f operator+(const mat4f l, const mat4f &v);
		mat4f& operator+=(const mat4f &v);
		friend mat4f operator-(const mat4f l, const mat4f &v);
		mat4f& operator-=(const mat4f &v);
		friend mat4f operator*(const mat4f l, const mat4f &v);
		friend mat4f operator*(const float l, const mat4f &v);
		mat4f& operator*=(const mat4f &v);
		friend mat4f operator/(const mat4f l, const mat4f &v);
		friend mat4f operator/(const float l, const mat4f &v);
		mat4f& operator/=(const mat4f &v);
		friend std::ostream& operator<<(std::ostream& out, const mat4f& v);
		float mod();

		mat4f inverse();
		mat4f transpose();
		static mat4f identity();
		static mat4f diagonal(float element);

	};
}