/*************************************************************************
	> File Name: 21.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 14时57分38秒
 ************************************************************************/

#include<iostream>
#include <cmath>
#include <cinttypes>
using namespace std;
#define max_n 10000000

int sum[max_n + 5];
int64_t cnt[max_n + 5];//存放的是最小素因子幂次
int prime[max_n + 5];
void init();

int main() {
    init();
    /*
    for (int j = 1; j < 100; j++) {
        printf("sum[%d] = %d\n", j, sum[j]);
    }
    */
    int ans = 0;
    for (int i = 1; i < max_n; i++) {
        sum[i] -= i;
    }
    for (int i = 1; i < max_n; i++) {
        if ((sum[i] < max_n) && (sum[sum[i]] == i) && (i != sum[i])) 
            ans += i;
    }
    printf("%d\n", ans);
    return 0;
}

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            cnt[i] = i * i;
            sum[i] = 1 + i;
        }
        for (int j = 1; j <= prime[0] && (i * prime[j] <= max_n); j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                sum[i * prime[j]] = sum[i] * (1 - cnt[i] * prime[j]) / (1 - cnt[i]);
                //为什么cnt的定义变了之后就不能先除后乘呢？？？
                //这个问题在21.3中解释了
                cnt[i * prime[j]] = cnt[i] * prime[j];
                break;
            } else {
                cnt[i * prime[j]] = prime[j] * prime[j];
                sum[i * prime[j]] = sum[i] * sum[prime[j]];
            }
        }
    }
    return ;
}
