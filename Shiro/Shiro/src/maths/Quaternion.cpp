#include "quaternion.h"
namespace shiro
{
	quaternion::quaternion()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	quaternion::quaternion(float x, float y, float z, float w):x(x),y(y),z(z),w(w)
	{
	}
	quaternion::quaternion(const vec4f & v):x(v.x),y(v.y),z(v.z),w(v.w)
	{
	}
	quaternion::quaternion(const quaternion & q):x(q.x),y(q.y),z(q.z),w(q.w)
	{
	}
	quaternion::quaternion(const vec3f & v, float w)
	{
		x		= v.x;
		y		= v.y;
		z		= v.z;
		this->w = w;
	}
	quaternion::quaternion(float f)
	{
		x = f;
		y = f;
		z = f;
		w = f;
	}
	quaternion quaternion::Identity()
	{
		return quaternion(0.0f,0.0f,0.0f,1.0f);
	}

	quaternion quaternion::FromEulerAngles(const vec3f& angles)
	{
		quaternion pitch(vec3f(1.0, 0.0, 0.0), angles.x);
		quaternion yaw(vec3f(0.0, 1.0, 0.0), angles.y);
		quaternion roll(vec3f(0.0, 0.0, 1.0), angles.z);
		return pitch * yaw * roll;
	}

	float quaternion::Norm(const quaternion & q)
	{
		float result;
		result = (q.x * q.x);
		result = (result + (q.y * q.y));
		result = (result + (q.z * q.z));
		result = (result + (q.w * q.w));
		return result;
	}

	quaternion quaternion::Normalize(const quaternion & q)
	{
		float lenSqr, lenInv;
		lenSqr = Norm(q);
		lenInv = sqrt(lenSqr);
		return q * lenInv;
	}

	quaternion operator*(const quaternion l, const quaternion & r)
	{
		return quaternion::Normalize(quaternion(
			(((l.w * r.x) + (l.x * r.w)) + (l.y * r.z)) - (l.z * r.y),
			(((l.w * r.y) + (l.y * r.w)) + (l.z * r.x)) - (l.x * r.z),
			(((l.w * r.z) + (l.z * r.w)) + (l.x * r.y)) - (l.y * r.x),
			(((l.w * r.w) - (l.x * r.x)) - (l.y * r.y)) - (l.z * r.z)
		));
	}

}
