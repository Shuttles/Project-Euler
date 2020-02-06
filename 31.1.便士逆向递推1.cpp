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
//f[i][j] = f[i - 1][j] + f[i][j - w[i]];
int w[max_m + 5] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

int f[max_m + 5][max_n + 5]; 


int main() {
    for (int i = 1; i <= max_m; i++) {
        f[i][0] = 1;//注意不能是0;一是为了初始化推动这个数组，二是是语义信息更加缜密，因为当24行j==w[i]即一定用到第i中硬币时一定有1种方法
        for (int j = 1; j <= max_n; j++) {
            f[i][j] = f[i - 1][j];
            if (j - w[i] >= 0) f[i][j] += f[i][j - w[i]];//这里一定是大于等于0！！！！！
        }
    }
    printf("%d\n", f[max_m][max_n]);
    return 0;
}


