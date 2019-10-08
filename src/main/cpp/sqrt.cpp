/* 实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
*/

#include <stdio.h>
#include <assert.h>

int mySqrt(int x) {
    assert(x >= 0);

    if (x == 0 || x == 1)
        return x;

    int left = 1;
    int right = x;
    int mid = 0;

    while (left < right) {
        mid = (left + right + 1) >> 1;
        if (mid < x / mid) left = mid;
        else right = mid - 1;
    }

    return mid;
}

int main() {
    printf("%d\n", mySqrt(16));
    printf("%d\n", mySqrt(8));
    printf("%d\n", mySqrt(2147483647));
    printf("%d\n", mySqrt(1));
    return 0;
}
