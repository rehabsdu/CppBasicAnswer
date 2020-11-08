// Code 15-2

class Vector4
{
	float _data[4];
public:
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