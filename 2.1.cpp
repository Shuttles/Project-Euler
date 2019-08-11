/*************************************************************************
	> File Name: 2.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 15时04分35秒
 ************************************************************************/
//这种方法，每次循环到一个数时，总要调用递归程序去得到这个数，所以时间空间复杂度都很高，是少年宇写的弟中弟解法
#include<iostream>
using namespace std;

int Fibonacci(int n);

int main() {
    int sum = 0;
    for (int i = 2; Fibonacci(i) <= 4000000; i++) {
        if (!(Fibonacci(i) % 2)) sum += Fibonacci(i);
    }
    printf("%d\n", sum);
    return 0;
}

int Fibonacci(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
