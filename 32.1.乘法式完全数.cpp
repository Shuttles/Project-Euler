/*************************************************************************
	> File Name: 32.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 15时44分17秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#define max_n 10000
using namespace std;

int keep[max_n + 5];

inline int digits(int x);

inline int add_to_num(int x, int *num);

int is_pandigital(int a, int b, int c);

int main() {
    int sum = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = a + 1; b < 10000; b++) {
            if (!is_pandigital(a, b, a * b)) continue;
            if (keep[a * b]) continue;//如果已经存过该数就跳过
            printf("%d * %d = %d\n", a, b, a * b);
            sum += a * b;
            keep[a * b] = 1;
        }
    }
    printf("%d\n", sum);

    return 0;
}

inline int add_to_num(int x, int *num) {
    while (x) {
        if (num[x % 10]) return 0;
        num[x % 10] += 1;
        x /= 10;
    }
    return 1;
}

int is_pandigital(int a, int b, int c) {
    if (digits(a) + digits(b) + digits(c) - 9) return 0;//判断是不是一共九位
    int num[10] = {0};
    num[0] = 1;
    int flag = 1;
    flag = flag && add_to_num(a, num);
    flag = flag && add_to_num(b, num);
    flag = flag && add_to_num(c, num);//判断有无重复出现的数字
    return flag;
}

inline int digits(int x) {
    return floor(log10(x)) + 1;//该基操就是取位数
}
