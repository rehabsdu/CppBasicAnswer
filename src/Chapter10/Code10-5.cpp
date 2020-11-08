// Code 10-5
#include <vector>
#include <algorithm>
using namespace std;

// example for insert sort

void mySort(vector<int>& nums)
{
	for (auto iter = nums.begin(); iter != nums.end(); ++iter)
	{
		int value = *iter;
		auto pos = nums.begin();
		while (pos != iter) {
			if (*pos > value) {
				break;
			}
			++pos;
		} // 此时pos指向第一个大于value的位置
		for (auto pIter = iter; pIter > pos; --pIter) {
			*pIter = *(pIter - 1);
		} // 将iter之前的元素依次后移一个
		*pos = value;
	}
}