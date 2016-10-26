#include "vec3f.h"

namespace shiro {

	vec3f::vec3f()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	vec3f::vec3f(float x, float y, float z) :x(x), y(y), z(z)
	{
	}

	vec3f::vec3f(const vec3f &v) : x(v.x), y(v.y), z(v.z)
	{
	}

	vec3f operator+(vec3f l, const vec3f & v)
	{
		vec3f n;

		n.x = l.x + v.x;
		n.y = l.y + v.y;
		n.z = l.z + v.z;
		return n;
	}
	vec3f & vec3f::operator+=(const vec3f & v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		return *this;
	}
	vec3f vec3f::operator-(const vec3f & v)
	{
		vec3f n;

		n.x = this->x - v.x;
		n.y = this->y - v.y;
		n.z = this->z - v.z;
		return n;
	}
	vec3f & vec3f::operator-=(const vec3f & v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		return *this;
	}

	vec3f & vec3f::operator*=(const float i)
	{
		this->x *= i;
		this->y *= i;
		this->z *= i;
		return *this;
	}

	vec3f & vec3f::operator*=(const vec3f & v)
	{
		this->x = (this->y * v.z - this->z*v.y);
		this->y = -(this->x * v.z - this->z * v.x);
		this->z = (this->x * v.y - this->y * v.x);
		return *this;
	}

	vec3f & vec3f::operator/=(const float i)
	{
		this->x /= i;
		this->y /= i;
		this->z /= i;
		return *this;
	}

	float vec3f::mod()
	{
		return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
	}

	vec3f vec3f::up()
	{
		return vec3f(0,1,0);
	}

	vec3f vec3f::down()
	{
		return vec3f(0,-1,0);
	}

	vec3f vec3f::forward()
	{
		return vec3f(0,0,1);
	}

	vec3f vec3f::back()
	{
		return vec3f(0,0,-1);
	}

	vec3f vec3f::left()
	{
		return vec3f(-1,0,0);
	}

	vec3f vec3f::right()
	{
		return vec3f(1,0,0);
	}

	vec3f vec3f::one()
	{
		return vec3f(1,1,1);
	}

	vec3f vec3f::zero()
	{
		return vec3f(0,0,0);
	}

	vec3f operator*(vec3f l, const float m)
	{
		vec3f n;
		n.x = l.x * m;
		n.y = l.y * m;
		n.z = l.z * m;
		return n;
	}

	vec3f operator*(vec3f l, const vec3f & v)
	{
		vec3f n;
		n.x = (l.y * v.z - l.z*v.y);
		n.y = -(l.x * v.z - l.z * v.x);
		n.z = (l.x * v.y - l.y * v.x);
		return n;
	}

	vec3f operator/(vec3f l, const float m)
	{
		vec3f n;
		n.x = l.x * m;
		n.y = l.y * m;
		n.z = l.z * m;
		return n;
	}

	std::ostream& operator<<(std::ostream& out, const vec3f& v)
	{
		return out << "(" << v.x << "," << v.y << "," << v.z << ")";
	}
}
