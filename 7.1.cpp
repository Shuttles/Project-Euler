/*************************************************************************
	> File Name: 7.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 15时08分49秒
 ************************************************************************/

#include <stdio.h>
#define max_n 200000

int prime[max_n + 5] = {0};

int main() {
    long long i, j, k, t;
    for (i = 2; i <= max_n; i++) {
        if (prime[i] == 0) {
            for (j = i * i; ; j += i) {
                if (j > max_n) break;
                prime[j] = 1;
            }
        }
    } 
    for (i = 2; i <= max_n; i++) {
        if (prime[i] == 0)
            prime[++prime[0]] = i;
    }
    printf("%d\n", prime[10001]);
    fflush(stdout);
    return 0;
}
