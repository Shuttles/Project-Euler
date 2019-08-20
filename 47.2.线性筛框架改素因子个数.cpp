/*************************************************************************
	> File Name: 47.2.线性筛框架改素因子个数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 10时28分19秒
 ************************************************************************/

#include <iostream>
#define max_n 1000000
using namespace std;

int cnt[max_n + 5];//这个数组用来存放对应下标的数字的素因子个数；
int prime[max_n + 5];
void init();

int main() {
    init();
    int n = 644;
    for (; n <= max_n; n++) {
        if (cnt[n] != 4) continue;
        if (cnt[n] != cnt[n + 1]) continue;
        if (cnt[n + 1] != cnt[n + 2]) continue;
        if (cnt[n + 2] != cnt[n + 3]) continue;
        printf("%d\n", n);
        break;
    }
    return 0;
}

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0] && (i * prime[j] <= max_n); j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j]) {
                cnt[i * prime[j]] = cnt[i] + 1;
            } else {
                cnt[i * prime[j]] = cnt[i];
                break;
            }
        }
    }
    
    return ;
}
