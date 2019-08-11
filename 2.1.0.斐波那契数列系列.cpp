/*************************************************************************
	> File Name: 2.1.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月08日 星期四 11时39分05秒
 ************************************************************************/
 //少年宇将记忆化方法应用到斐波那契数列的递归方法上，提速八十倍！！！
 //斐波那契数列第33项就已超四百万！！！
#include<stdio.h>
#define max_n 4000000

int fib0[max_n];
int fib(int x);

int main() {
    int i = 2, j;
    int sum = 0;
    while (fib(i) < max_n) {
        if (!(fib(i) & 1)) sum += fib(i);
        i++;
    }
    printf("%d\n", sum);
    printf("%d\n", fib(33));
    return 0;
}

int fib(int x) {
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x < max_n && fib0[x] != 0) return fib0[x];
    int temp = fib(x - 1) + fib(x - 2);
    if (x < max_n) fib0[x] = temp;
    return temp;
}

