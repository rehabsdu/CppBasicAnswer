// Code 14-1

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

// 用来判断乘10后会不会溢出
int tenthMax = INT32_MAX / 10;
// 判断一个字符是不是数字
inline bool isDigit(const char c)
{
    return c >= '0' && c <= '9';
}
// 将一个char转换为表示的数字
inline int ctoi(const char c, bool neg = false)
{
    return (c - '0') * (neg ? -1 : 1);
}
// 判断当前的数字加上下一位后会不会溢出
inline bool willOverflow(int now, const char toAdd, const bool neg)
{
    if (now > tenthMax || now < -tenthMax) {
        return true;
    }
    if (now < tenthMax && now > -tenthMax) {
        return false;
    }
    int thres = neg ? '8' : '7';
    return toAdd > thres;
}

int myAtoi(const char* s)
{
    int ret = 0;
    int bits = 0;
    string str = string(s);
    auto iter = str.begin();

    for (; iter != str.end(); ++iter) {
        if (*iter == '+' || *iter == '-' || isDigit(*iter)) {
            break;
        }
        if (*iter == ' ') {
            continue;
        }
        else {
            return 0;
        }
    }
    if (iter == str.end()) {
        return 0;
    }

    bool neg = (*iter == '-' ? true : false);
    if (!isDigit(*iter))
        ++iter;
    for (; iter != str.end() && isDigit(*iter); ++iter) {
        if (ret == 0) {
            ret += ctoi(*iter);
            ret *= (neg ? -1 : 1);
            continue;
        }
        if (willOverflow(ret, *iter, neg)) {
            return neg ? INT32_MIN : INT32_MAX;
        }
        ret *= 10;
        ret += ctoi(*iter, neg);
    }
    return ret;
}