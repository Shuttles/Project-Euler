/*************************************************************************
	> File Name: 0.000.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月20日 星期二 16时29分02秒
 ************************************************************************/
#include <iostream>
#include <cinttypes>
#define max_n 10000
using namespace std;

int cnt[max_n + 5];//存放最小素因子幂次
int prime[max_n + 5];
int sum_of_divisors[max_n + 5];//存放因子和
void init();

int main() {
    init();
    
    for (int i = 1; i < 100; i++) {
        printf("sum[%d] = %d\n", i, sum_of_divisors[i]);
    }
    
    for (int i = 1; i < max_n; i++) {
        sum_of_divisors[i] -= i;
    }
    int sum = 0;
    for (int i = 1; i < max_n; i++) {
        if ((sum_of_divisors[i] < max_n) && (sum_of_divisors[i] != i) && (sum_of_divisors[sum_of_divisors[i]] == i))
            sum += i;
    }
    printf("%d\n", sum);
    return 0;
}

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            sum_of_divisors[i] = 1 + i;
            cnt[i] = i;
        }
        for (int j = 1; j <= prime[0] && (i * prime[j] <= max_n); j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j]) {
                sum_of_divisors[i * prime[j]] = sum_of_divisors[i] * sum_of_divisors[prime[j]];    
                cnt[i * prime[j]] = prime[j]; 
            } else {
                sum_of_divisors[i * prime[j]] = sum_of_divisors[i] / (1 - cnt[i] * prime[j]) * (1 - cnt[i] * prime[j] * prime[j]);
                cnt[i * prime[j]] = cnt[i] * prime[j];
                break;
            }
        }
    }
    return;
}
