// Code 10-4
#include <list>
#include <algorithm>
using namespace std;

void deleteOddElement(list<int>& lst)
{
	for (auto iter = lst.begin(); iter != lst.end();)
	{
		if (*iter % 2 == 0) {
			++iter;
		}
		else {
			iter = lst.erase(iter);
		}
	}
}