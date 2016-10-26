#pragma once
#include "mat4f.h"
#include "vec3f.h"
#include "vec4f.h"
namespace shiro
{
	class quaternion
	{
	public:
		float x, y, z, w;
		quaternion();
		quaternion(float x, float y, float z, float w);
		quaternion(const vec4f &v);
		quaternion(const quaternion &q);
		quaternion(const vec3f &v, float w);
		quaternion(float f);
		
		static quaternion Identity();
		static quaternion FromEulerAngles(const vec3f& angles);


		friend quaternion operator*(const quaternion l, const quaternion &r);

		static float Norm(const quaternion &q);
		static quaternion Normalize(const quaternion &q);

	};
}