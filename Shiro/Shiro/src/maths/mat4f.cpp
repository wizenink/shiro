#include "mat4f.h"
namespace shiro
{
	mat4f::mat4f()
	{
		int i = 0;
		for (i; i < MAX_ELEMENTS; i++) {
			this->elements[i] = 0;
		}
	}

	mat4f::mat4f(const std::vector<float> & v)
	{
		int i = 0;
		for (i; i < MAX_ELEMENTS; i++) {
			this->elements[i] = v.at(i);
		}
	}

	mat4f::mat4f(const mat4f & v)
	{
		int i = 0;
		for (i; i < MAX_ELEMENTS; i++) {
			this->elements[i] = v.elements[i];
		}
	}

	mat4f operator+(const mat4f l, const mat4f & v)
	{
		int i = 0;
		mat4f newmatrix = mat4f();
		for (i; i < MAX_ELEMENTS; i++) {
			newmatrix.elements[i] = l.elements[i] + v.elements[i];
		}
		return newmatrix;
	}

	mat4f operator-(const mat4f l, const mat4f & v)
	{
		int i = 0;
		mat4f newmatrix = mat4f();
		for (i; i < MAX_ELEMENTS; i++) {
			newmatrix.elements[i] = l.elements[i] - v.elements[i];
		}
		return newmatrix;
	}

	mat4f operator*(const mat4f l, const mat4f & v)
	{
		int i = 0;
		int j = 0;
		mat4f newmatrix = mat4f();
		for (i; i < MAX_ELEMENTS; i + 4)
			for (j; j < 4; j++)
				newmatrix.elements[i + j] = (l.elements[j] * v.elements[i]) + (l.elements[j+4] * v.elements[i+1]) + (l.elements[j+8] * v.elements[i+2]) + (l.elements[j+12] * v.elements[i+3]);
		return newmatrix;
	}

	mat4f operator*(const float l, const mat4f & v)
	{
		int i = 0;
		mat4f newmatrix = mat4f();
		for (i; i < MAX_ELEMENTS; i++) {
			newmatrix.elements[i] = l * v.elements[i];
		}
		return mat4f();
	}

	mat4f & mat4f::operator+=(const mat4f & v)
	{
		int i = 0;
		for (i; i < MAX_ELEMENTS; i++) {
			this->elements[i] += v.elements[i];
		}
		return *(this);
	}

	mat4f & mat4f::operator-=(const mat4f & v)
	{
		int i = 0;
		for (i; i < MAX_ELEMENTS; i++) {
			this->elements[i] -= v.elements[i];
		}
		return *(this);
	}

	mat4f & mat4f::operator*=(const mat4f & v)
	{
		int i = 0;
		int j = 0;
		mat4f l = mat4f(*this);
		for (i; i < MAX_ELEMENTS; i + 4)
			for (j; j < 4; j++)
				this->elements[i + j] = (l.elements[j] * v.elements[i]) + (l.elements[j + 4] * v.elements[i + 1]) + (l.elements[j + 8] * v.elements[i + 2]) + (l.elements[j + 12] * v.elements[i + 3]);

		return *(this);
	}


}