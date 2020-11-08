// Code 16-3

#include <string>
#include <exception>
#include <stdlib.h>
using namespace std;

bool sameSign(const int a, const int b)
{
	return (a >= 0 && b >= 0) || (a < 0 && b < 0);
}
class myIntOverflow : public overflow_error
{
public:
	myIntOverflow(const char* msg) : overflow_error(msg)
	{	}
	myIntOverflow(const string& s): overflow_error(s)
	{   }
};
class myInt
{
	int _num;
	char msg[1000];
	
public:
	myInt() = default;
	explicit myInt(int v) : _num(v) { }

	int value() const { return _num; }
	myInt& operator+=(const myInt& rhs)
	{
		int sum = rhs._num + _num;
		if (sameSign(rhs._num, _num))
		{
			if (!sameSign(sum, _num)) {
				sprintf_s(msg, "addtional overflow detected: %d + %d", _num, rhs._num);
				throw myIntOverflow(msg);
			}
		}
		_num = sum;
		return *this;
	}
	myInt& operator-=(const myInt& rhs)
	{
		if (rhs._num == INT_MIN && _num >= 0) {
			sprintf_s(msg, "addtional overflow detected: %d + %d", _num, rhs._num);
			throw myIntOverflow("addtional overflow ");
		}
		if (rhs._num == INT_MIN) {
			_num -= rhs._num;
			return *this;
		}
		return operator+=(myInt(-rhs._num));
	}
	myInt& operator*=(const myInt& rhs)
	{
		long long res = (long long)rhs._num * (long long)_num;
		if (res > INT_MAX || res < INT_MIN) {
			sprintf_s(msg, "multiplicative overflow detected: %d * %d", _num, rhs._num);
			throw myIntOverflow(msg);
		}
		_num = res;
		return *this;
	}
	myInt& operator/=(const myInt& rhs)
	{
		if (rhs._num == 0) {
			throw myIntOverflow("overflow detected: divided by zero");
		}
		_num /= rhs._num;
	}
};

myInt operator-(const myInt& n)
{
	if (n.value() == INT_MIN) {
		throw myIntOverflow("overflow detected: int cannot express 2^31");
	}
	return myInt(-n.value());
}