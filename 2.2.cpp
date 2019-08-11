/*************************************************************************
	> File Name: 2.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 15时29分40秒
 ************************************************************************/
//我写的2.1.cpp的时间是2.2.cpp的时间的81倍
//小技巧：把fib[0]当成计数器，类似技巧在素数筛中也有应用
#include<iostream>
#define max_n 4000000
using namespace std;

int fib[45] = {2, 1, 2};

int main() {
    while (fib[fib[0]] + fib[fib[0] - 1] < max_n) {
        fib[0]++;
        fib[fib[0]] = fib[fib[0] - 1] + fib[fib[0] - 2];
    }

    long long  sum = 0;
    for (int i = 1; i <= fib[0]; i++) {
        if (!(fib[i] & 1)) sum += fib[i];
    }
    printf("%lld\n", sum);
    return 0;
}
