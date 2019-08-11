/*************************************************************************
	> File Name: 7.001.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 16时03分04秒
 ************************************************************************/

#include <stdio.h>
#define max_n 10000
int prime[max_n + 5] = {0};

int main() {
    int i, j;
    for (i = 2; i * i <= max_n; i++) {
        if (!prime[i]) {
            for (j = i * i; j <= max_n; j += i) {
                prime[j] = 1;
            }
        }
    }
    for (i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
    }




    return 0;
}
