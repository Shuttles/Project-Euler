/*************************************************************************
	> File Name: 31.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 14时33分12秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#define max_n 200
#define max_m 8
using namespace std;

int w[max_m + 5] = {1, 2, 5, 10, 20, 50, 100, 200};

int f[max_n + 5]; 


int main() {
    f[0] = 1;
    for (int k = 0; k < max_m; k++) {
        for (int j = w[k]; j <= max_n; j++) {
            //if (j - w[k] >= 0)
                f[j] += f[j - w[k]];
        }
    }
    printf("%d\n", f[max_n]);
    return 0;
}


