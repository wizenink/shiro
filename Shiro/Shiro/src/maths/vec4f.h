#pragma once
namespace shiro {
	class vec4f {
	private:
		float x, y, z, w;
	public:
		vec4f();
		vec4f(float x, float y, float z, float w);
		vec4f(const vec4f &v);

	};
}