#include "vec4f.h"

shiro::vec4f::vec4f()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

shiro::vec4f::vec4f(float x, float y, float z, float w):x(x),y(y),z(z),w(w)
{
}

shiro::vec4f::vec4f(const vec4f &v)
{
}
