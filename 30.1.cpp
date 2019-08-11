/*************************************************************************
	> File Name: 30.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 16时04分13秒
 ************************************************************************/
//如果调用pow函数，则运行时间将是不调用的5倍！！！！
#include <stdio.h>
#include <math.h>
#define MAX_N 354294
#define max_n 98700

int is_val(int x);

int main() {
    int sum = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}

int is_val(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum += (x % 10) * (x % 10) * (x % 10) * (x % 10) * (x % 10);
        x /= 10;
    }
    return sum == temp;
}
