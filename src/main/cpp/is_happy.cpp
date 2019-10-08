/*编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例:

输入: 19
输出: true
解释:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sqrt_sum(int n) {
    int sum = 0;
    while (n > 0) {
        int b = n % 10;
        sum += b * b;
        n = n / 10;
    }
    return sum;
}

bool is_happy(int n) {
    if (n <= 0) {
        return false;
    }
    int slow = n;
    int fast = sqrt_sum(n);
    while (slow != fast) {
        slow = sqrt_sum(slow);
        fast = sqrt_sum(fast);
        fast = sqrt_sum(fast);
    }
    return slow == 1;
}

int main(int argc, char *argv[])
{
    printf("%d\n", is_happy(19));
    printf("%d\n", is_happy(20));
    return 0;
}
