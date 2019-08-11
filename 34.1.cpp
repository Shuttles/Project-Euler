/*************************************************************************
	> File Name: 34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 18时05分41秒
 ************************************************************************/

#include<iostream>
#define max_n 2540160
using namespace std;

int factorial[10] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int is_val(int x);

int main() {
    int sum = 0;
    for (int j = 2; j <= 9; j++) {
        factorial[j] = j * factorial[j - 1];
    }
    for (int i = 3; i <= max_n; i++) {
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}

int is_val(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum += factorial[x % 10];
        x /= 10;
    }
    return temp == sum;
}
