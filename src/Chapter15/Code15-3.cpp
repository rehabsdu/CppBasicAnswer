// Code 15-3

#include <algorithm>
#include <stdlib.h>
using namespace std;

class Vector4
{
	float _data[4];
public:
	friend class Matrix4;
	Vector4() = default;
	Vector4(float a, float b, float c, float d)
	{
		_data[0] = a; _data[1] = b;
		_data[2] = c; _data[3] = d;
	}

	Vector4& operator+=(const Vector4& rhs)
	{
		for (int i = 0; i < 4; ++i) {
			_data[i] += rhs._data[i];
		}
		return *this;
	}
	Vector4& operator-=(const Vector4& rhs)
	{
		for (int i = 0; i < 4; ++i) {
			_data[i] -= rhs._data[i];
		}
		return *this;
	}
	float& operator[](size_t x)
	{
		return _data[x];
	}
	friend int operator*(const Vector4& lhs, const Vector4& rhs);
};

Vector4 operator+(const Vector4& lhs, const Vector4& rhs)
{
	auto tmp = lhs;
	tmp += rhs;
	return tmp;
}
Vector4 operator-(const Vector4& lhs, const Vector4& rhs)
{
	auto tmp = lhs;
	tmp -= rhs;
	return tmp;
}
int operator*(const Vector4& lhs, const Vector4& rhs)
{
	int s = 0;
	for (int i = 0; i < 4; ++i) {
		s += lhs._data[i] * rhs._data[i];
	}
	return s;
}

class Matrix4
{
	typedef Vector4 vec;
	vec _columns[4];
public:
	Matrix4(const vec a, const vec b, const vec c, const vec d)
	{
		_columns[0] = a; _columns[1] = b;
		_columns[2] = c; _columns[3] = d;
	}
	Matrix4& operator+=(const Matrix4& rhs)
	{
		for (int i = 0; i < 4; ++i) {
			_columns[i] += rhs._columns[i];
		}
		return *this;
	}
	Matrix4& operator-=(const Matrix4& rhs)
	{
		for (int i = 0; i < 4; ++i) {
			_columns[i] -= rhs._columns[i];
		}
		return *this;
	}
	Matrix4& operator*=(const Matrix4& rhs)
	{
		vec rows[4];
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				rows[i]._data[j] = _columns[j]._data[i];
			}
		}
		vec temp[4];
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				_columns[i]._data[j] = rows[j] * rhs._columns[i];
			}
		}
		return *this;
	}
	vec& operator[](size_t x)
	{
		return _columns[x];
	}
	Matrix4 transpose()
	{
		Matrix4 t = *this;
		for (int i = 0; i < 3; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				swap(_columns[j]._data[i], _columns[i]._data[j]);
			}
		}
		return t;
	}
};

Matrix4 operator+(const Matrix4& lhs, const Matrix4& rhs)
{
	auto tmp = lhs;
	tmp += rhs;
	return tmp;
}
Matrix4 operator-(const Matrix4& lhs, const Matrix4& rhs)
{
	auto tmp = lhs;
	tmp -= rhs;
	return tmp;
}
Matrix4 operator*(const Matrix4& lhs, const Matrix4& rhs)
{
	auto tmp = lhs;
	tmp *= rhs;
	return tmp;
}