// Code 15-5

#pragma once
#include <cstring>
#include <memory>
#include <iostream>
#include <cassert>

class myString
{
	char* _str;
	size_t _size;
	size_t _capacity;

	void allocMoreMemory()
	{
		if (_str == nullptr) {
			_str = new char[1];
			_capacity = 1;
			return;
		}
		size_t oldcapa = _capacity;
		char* oldMemory = _str;
		
		_size = _size * 2;
		_str = new char[_size];
		std::uninitialized_copy_n(oldMemory, oldcapa, _str);
		delete[] oldMemory;
	}
public:
	myString() : _str(nullptr), _size(0), _capacity(0) {}
	explicit myString(const char* s)
	{
		size_t slen = strlen(s);
		reserve(slen);
		std::uninitialized_copy_n(s, slen, _str);
		_size = slen;
	}
	size_t size() const
	{
		return _size;
	}
	char* c_str() const
	{
		return _str;
	}
	void push_back(const char c)
	{
		if (_size + 1 >= _capacity) {
			allocMoreMemory();
		}
		_str[_size] = c;
		++_size;
		_str[_size] = '\0';
	}
	void pop_back()
	{
		--_size;
	}
	myString& operator=(const myString& s)
	{
		if (this == &s) {
			return *this;
		}
		if (_str != nullptr) {
			delete[] _str;
		}
		_capacity = s._capacity;
		_size = s._size;
		_str = new char[_capacity];
		std::uninitialized_copy_n(s._str, _capacity, _str);
		return *this;
	}
	myString& operator+=(const myString& s)
	{
		size_t nSize = _size + s._size;
		reserve(nSize);
		std::uninitialized_copy_n(s._str, s._size, _str + _size);
		_size = nSize;
		return *this;
	}
	char& operator[](const size_t x) const
	{
		assert(x <= _size);
		return _str[x];
	}
	friend bool operator==(const myString& s1, const myString& s2);
	friend myString operator*(const myString& s, const int x);
	
	void reserve(size_t n)
	{
		if (n <= _capacity) {
			return;
		}
		char* newMemo = new char[n];
		if (_str != nullptr) {
			std::uninitialized_copy_n(_str, _capacity, newMemo);
			delete[] _str;
		}
		_str = newMemo;
		_capacity = n;
	}
};

bool operator==(const myString& s1, const myString& s2)
{
	if (s1.size() == s2.size()) {
		for (int i = 0; i < s1.size(); ++i) {
			if (s1._str[i] != s2._str[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

myString operator+(const myString& s1, const myString& s2)
{
	auto tmp = s1;
	tmp += s2;
	return tmp;
}

myString operator*(const myString& s, const int x)
{
	assert(x >= 1);
	myString res;
	if (s.size() == 0) {
		return res;
	}

	res.reserve(x * s.size() + 1);
	for (int i = 0; i < x; ++i) {
		std::uninitialized_copy_n(s._str, s.size(), res._str + i * s.size());
	}
	res._size = s.size() * x;
	res._str[res._size] = '\0';
	return res;
}