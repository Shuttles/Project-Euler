/*************************************************************************
	> File Name: 21.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 14时57分38秒
 ************************************************************************/

#include<iostream>
#include <cmath>
using namespace std;
#define max_n 1000000

int sum[max_n + 5];
int f[max_n + 5];
int cnt[max_n + 5];//存放的是最小素因子的幂次
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
    for (int i = 2; i < max_n; i++) {
        sum[i] -= i;
    }
    for (int i = 2; i < max_n; i++) {
        if (sum[i] < max_n && (sum[sum[i]] == i) && (i != sum[i])) {
            printf("i = %d, sum[i] = %d\n", i, sum[i]);       
            ans += i;
        }
    }
    printf("%d\n", ans);
    return 0;
}

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
            sum[i] = 1 + i;
        }
        for (int j = 1; j <= prime[0] && (i * prime[j] <= max_n); j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                sum[i * prime[j]] = sum[i] / (1 - pow(prime[j], cnt[i] + 1)) * (1 - pow(prime[j], cnt[i] + 2));
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                f[i * prime[j]] = f[i] * 2;
                cnt[i * prime[j]] = 1;
                sum[i * prime[j]] = sum[i] * sum[prime[j]];
            }
        }
    }
    return ;
}
