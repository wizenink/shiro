#include "vec4f.h"

namespace shiro {

	vec4f::vec4f()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	vec4f::vec4f(float x, float y, float z, float w):x(x),y(y),z(z),w(w)
	{
	}

	vec4f::vec4f(const vec4f &v): x(v.x),y(v.y),z(v.z),w(v.w)
	{
	}

	vec4f operator+(vec4f l,const vec4f & v)
	{
		vec4f n;
		
		n.x = l.x + v.x;
		n.y = l.y + v.y;
		n.z = l.z + v.z;
		n.w = l.w + v.w;
		return n;
	}
	vec4f & vec4f::operator+=(const vec4f & v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		this->w += v.w;

		return *this;
	}
	vec4f vec4f::operator-(const vec4f & v)
	{
		vec4f n;

		n.x = this->x - v.x;
		n.y = this->y - v.y;
		n.z = this->z - v.z;
		n.w = this->w - v.w;
		return n;
	}
	vec4f & vec4f::operator-=(const vec4f & v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		this->w -= v.w;

		return *this;
	}

	vec4f & vec4f::operator*=(const int i)
	{
		this->x *= i;
		this->y *= i;
		this->z *= i;
		this->w *= i;
		return *this;
	}

	vec4f & vec4f::operator/=(const int i)
	{
		this->x /= i;
		this->y /= i;
		this->z /= i;
		this->w /= i;
		return *this;
	}

	float vec4f::mod()
	{
		return sqrt(this->x*this->x + this->y*this->y + this->z*this->z + this->w*this->w);
	}

	vec4f operator*(vec4f l, const float m)
	{
		vec4f n;
		n.x = l.x * m;
		n.y = l.y * m;
		n.z = l.z * m;
		n.w = l.w * m;
		return n;
	}

	vec4f operator/(vec4f l, const float m)
	{
		vec4f n;
		n.x = l.x * m;
		n.y = l.y * m;
		n.z = l.z * m;
		n.w = l.w * m;
		return n;
	}

	std::ostream& operator<<(std::ostream& out, const vec4f& v)
	{
		return out << "(" << v.x << "," << v.y << "," << v.z << "," << v.w << ")";
	}
}
