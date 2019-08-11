/*************************************************************************
	> File Name: 35.1.圆周素数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 18时01分20秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;
#define max_n 1000000
int digits(int x);

int prime[max_n + 5];

int prime1[max_n + 5];

int is_circular_prime(int x);

int main() {
    int sum = 0;
    for (int m = 2; m <= max_n; m++) {
        if (!prime1[m]) prime[++prime[0]] = m;   
        for (int i = 1; i <= prime[0]; i++) {
            if (m * prime[i] > max_n) break;
            prime1[m * prime[i]] = 1;
            if (m % prime[i] == 0) break;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        if (is_circular_prime(i)) 
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}

int digits(int x) {
    return floor(log10(x)) + 1;    
}

int is_circular_prime(int x) {
    if (x < 10 && (prime1[x] == 0)) return 1;
    int len = digits(x);
    int temp = x, h = (int)pow(10, len - 1);
    for (int i = 1; i <= len; i++) {
        temp = (temp % 10) * h + temp / 10;
        if (prime1[temp] != 0) return 0;
    }
    return 1;
}
