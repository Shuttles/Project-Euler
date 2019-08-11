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

int w[8 + 5] = {1, 2, 5, 10, 20, 50, 100, 200};

int f[2][max_n + 5]; 


int main() {
    for (int k = 0; k < 8; k++) {
        int i = k % 2;
        f[i][0] = 1;
        for (int j = 1; j <= max_n; j++) {
             f[i][j] = f[i % 2][j];
            if (j - w[k] >= 0) f[i][j] += f[i][j - w[k]];
        }
    }
    printf("%d\n", f[(max_m - 1) % 2][max_n]);
    return 0;
}


