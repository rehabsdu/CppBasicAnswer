// Code 16-5

#include <iostream>
using namespace std;

template <typename T>
class wrapper
{
	T _num;
public:
	explicit wrapper(const T& a) : _num(a) {}
	T excute(const wrapper& a) const
	{
		return _num + a._num;
	}
};
template <>
class wrapper<float>
{
	float _num;
public:
	explicit wrapper(const float& a) : _num(a) {}
	float excute(const wrapper<float>& a) const
	{
		return _num * a._num;
	}
};

template <typename T>
T example(const wrapper<T>& a, const wrapper<T>& b)
{
	return a.excute(b);
}

int main()
{
	wrapper<float> a(3.1), b(2.5);
	wrapper<int> c(1), d(2);

	cout << example(a, b) << endl;
	cout << example(c, d) << endl;
}