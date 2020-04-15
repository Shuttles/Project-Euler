/*************************************************************************
	> File Name: 31.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 14时33分12秒
 ************************************************************************/
//只使用了一维数组
#include <iostream>
#include <cstdio>
#define max_n 200
#define max_m 8
using namespace std;

int w[max_m + 5] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

int f[max_n + 5]; 


int main() {
    f[0] = 1;
    for (int i = 1; i <= 8; i++) {
        for (int j = w[i]; j <= 200; j++) {
            //if (j - w[i] >= 0)   j从w[i]开始 妙啊妙啊妙哉妙哉
                f[j] += f[j - w[i]];
        }
    }
    printf("%d\n", f[max_n]);
    return 0;
}


