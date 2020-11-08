// Code 14-4

#pragma once
/***********************
* myCout.h
* Excercise 14-4
***********************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using std::printf;
using std::sprintf;
using std::strlen;
using std::ios_base;

class myCout
{
public:
	myCout()
	{
		_buffer[0] = '\0';
		ios_base::sync_with_stdio(true);
	}
	~myCout()
	{
		ios_base::sync_with_stdio(false);
	}

	void out(const int x)
	{
		snprintf(_buffer, _BUFSIZE, intFormat, x);
		_output();
	}
	void out(const char* str)
	{
		snprintf(_buffer, _BUFSIZE, "%s", str);
		_output();
	}
	void out(const double x)
	{
		snprintf(_buffer, _BUFSIZE, "%.*f", _precision, x);
		_output();
	}
	void out(const float x)
	{
		out(double(x));
	}
	void out(const bool b)
	{
		if (_boolAlpha) {
			snprintf(_buffer, _BUFSIZE, (b ? "true" : "false"));
		}
		else {
			snprintf(_buffer, _BUFSIZE, "%d", (b ? 1 : 0));
		}
		_output();
	}
	void out(const char c)
	{
		snprintf(_buffer, _BUFSIZE, "%c", c);
		_output();
	}

	void hex()
	{
		_base = base::HEX;
		intFormat = "%x";
	}
	void oct()
	{
		_base = base::OCT;
		intFormat = "%o";
	}
	void dec()
	{
		_base = base::DEC;
		intFormat = "%d";
	}
	void boolalpha()
	{
		_boolAlpha = !_boolAlpha;
	}
	void setprecision(const int p)
	{
		_precision = p;
	}
	size_t getCount() const
	{
		return _lastCount;
	}
private:
	enum { _BUFSIZE = 10000 };
	char _buffer[10000];
	size_t _lastCount = 0;
	bool _boolAlpha = false;
	enum class base {
		HEX, OCT, DEC,
	};
	base _base = base::DEC;
	const char* intFormat = "%d";
	int _precision = 5;

	void _output()
	{
		printf(_buffer);
		_lastCount = strnlen(_buffer, _BUFSIZE);
	}
};