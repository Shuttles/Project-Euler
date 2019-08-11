/*************************************************************************
	> File Name: 37.truncatable_primes.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 18时48分04秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#define max_n 1000000 
using namespace std;

int prime[max_n + 5];
int prime1[max_n + 5];

void inital_prime() {
    for (int m = 2; m <= max_n; m++) {
        if (!prime1[m]) prime[++prime[0]] = m;
        for (int i = 1; i <= prime[0]; i++) {
            if (m * prime[i] > max_n) break;
            prime1[m * prime[i]] = 1;
            if ((m % prime[i]) == 0) break;
        }
    }
    return ;
}

int is_truncatable_primes(int x);

int main() {
    inital_prime();
    prime1[1] = 1;
    int sum = 0;
    int numbers = 0;
    for (int i = 5; i <= prime[0]; i++) {
        if (!is_truncatable_primes(prime[i])) continue;
        numbers++;
        sum += prime[i];
        printf("%d %d\n", numbers, prime[i]);
    }
    printf("%d\n", sum);
    return 0;
}


int is_truncatable_primes(int x) {
    int len = (int)floor(log10(x)) + 1;
    int h = (int)pow(10, len - 1);
    int y = x;
    for (int i = 1; i <= len; i++) {
        if (prime1[x]) return 0;
        x /= 10;
    }
    for (int i = 1; i <= len; i++) {
        if (prime1[y]) return 0;
        y %= h;
        h /= 10;
    }
    return 1;
}
