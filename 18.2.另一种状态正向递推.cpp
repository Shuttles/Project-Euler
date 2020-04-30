/*************************************************************************
	> File Name: 18.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 18时10分28秒
 ************************************************************************/
//这种状态的定义是：dfs(i, j, n)是从val[i][j]到最底层时的最大值
#include <iostream>
#include <cstdio>
using namespace std;
#define max_n 20

int val[max_n + 5][max_n + 5];
int keep[max_n + 5][max_n + 5];

int dfs(int i, int j, int n) {
    if (i + 1 == n) return keep[i][j] = val[i][j];
    if (keep[i][j]) return keep[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    int temp = (val1 > val2 ? val1 : val2) + val[i][j];
    keep[i][j] = temp;
    return temp;
}

int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    cout << dfs(0, 0, 15) << endl;
    /*下面是输出调试*/
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", keep[i][j]);
        }
        printf("\n");
    }
    return 0;
}

