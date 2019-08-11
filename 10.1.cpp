/*************************************************************************
	> File Name: 10.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 19时05分58秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 2000000

int prime[MAX_N + 5] = {0};

int main() {
    int64_t sum = 0;
    for (int m = 2; m < MAX_N; m++) {
        if (!prime[m]) prime[++prime[0]] = m, sum += m;
        for (int i = 1; i <= prime[0]; i++) {
            if (m * prime[i] >= MAX_N) break;
            prime[m * prime[i]] = 1;
            if (m % prime[i] == 0) break;
        }
    }
    printf("%" PRId64 "\n", sum);
    return 0;
}
