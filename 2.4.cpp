/*************************************************************************
	> File Name: 2.4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 16时07分48秒
 ************************************************************************/
//滚动数组法
#include <iostream>
#define max_n 4000000
using namespace std;

int fib[3] = {0,1};

int main() {
    int n = 1;
    int sum = 0;
    while (fib[n % 3] + fib[(n - 1) % 3] < max_n) {
        n++;
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        if (!(fib[n % 3] & 1)) sum += fib[n % 3];
    }
    printf("%d\n", sum);
    return 0;
}
