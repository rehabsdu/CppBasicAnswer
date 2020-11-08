// Code 10-6

#include <stdlib.h>
#include <string.h>
#include <assert.h>

class myVector
{
private:
	int* _data;
	int* _end;
	int* _finish;
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
		int* oldMemo = _data;
		_data = new int[_capacity];
		_finish = _data + _capacity;
		_end = _data + _size;
		memcpy(_data, oldMemo, _size * sizeof(int));
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
		int destTail = dest + (_size - from) - 1;
		int fromTail = _size - 1;
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

	void push_back(const int x)
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

	int& getItem(const size_t n) const
	{
		assert(n < _size);
		return _data[n];
	}
	
	void erase(const size_t beg, const size_t end)
	{
		assert(beg < _size&& end < _size && beg <= end);
		moveForward(beg, end + 1);
		_size -= end - beg;
		_end = _data + _size;
	}
	void erase(const size_t n)
	{
		assert(n < _size);
		erase(n, n);
	}
	void insert(const size_t pos, const int x)
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