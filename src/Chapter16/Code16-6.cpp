// Code 16-6

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

template <typename T>
class myVector
{
private:
	T* _data;
	T* _end;
	T* _finish;
	size_t _size;
	size_t _capacity;

	// 内存不足时分配当前二倍大小的内存
	void allocLargerMemory()
	{
		if (_capacity == 0) {
			_capacity = 1;
		}
		else {
			_capacity *= 2;
		}
		T* oldMemo = _data;
		_data = new T[_capacity];
		_finish = _data + _capacity;
		_end = _data + _size;
		memcpy_s(_data, _size * sizeof(int), oldMemo, _size * sizeof(int));
		if (oldMemo != nullptr) {
			delete[] oldMemo;
		}
	}
	// 将内存中以from开头的元素整体前移到dest开头的位置
	void moveForward(size_t dest, size_t from)
	{
		assert(dest < from);
		while (from < _size) {
			_data[dest++] = _data[from++];
		}
	}
	// 将内存中from开头的元素整体后移到dest开头的位置
	void moveBackward(size_t dest, size_t from)
	{
		assert(dest > from);
		T destTail = dest + (_size - from) - 1;
		T fromTail = _size - 1;
		while (destTail >= dest) {
			_data[destTail--] = _data[fromTail--];
		}
	}
public:
	myVector() :
		_data(nullptr), _end(nullptr), _finish(nullptr), _size(0), _capacity(0) {}
	explicit myVector(size_t count) : _size(count), _capacity(2 * count)
	{
		_data = new int[count * 2];
		_end = _data + count;
		_finish = _data + count * 2;
	}
	myVector(size_t count, int val) : myVector(count)
	{
		for (size_t i = 0; i < count; ++i)
		{
			_data[i] = val;
		}
	}
	~myVector()
	{
		if (_data != nullptr) {
			delete[] _data;
		}
	}

	void push_back(const T& x)
	{
		if (_size >= _capacity) {
			allocLargerMemory();
		}
		_data[_size++] = x;
		++_end;
	}
	void pop_back()
	{
		assert(_size != 0);
		--_size;
		--_end;
	}
	size_t size() const
	{
		return _size;
	}

	T& getItem(const size_t n) const
	{
		assert(n < _size);
		return _data[n];
	}

	void erase(const size_t beg, const size_t end)
	{
		assert(beg < _size&& end < _size&& beg <= end);
		moveForward(beg, end + 1);
		_size -= end - beg;
		_end = _data + _size;
	}
	void erase(const size_t n)
	{
		assert(n < _size);
		erase(n, n);
	}
	void insert(const size_t pos, const T& x)
	{
		assert(pos <= _size);
		if (pos == _size) {
			push_back(x);
			return;
		}
		if (_size >= _capacity) {
			allocLargerMemory();
		}
		moveBackward(pos + 1, pos);
		_data[pos] = x;
		++_size;
		++_end;
	}
};