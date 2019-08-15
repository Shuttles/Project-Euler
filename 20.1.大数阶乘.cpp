/*************************************************************************
	> File Name: 20.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 16时40分36秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#define max_n 200
using namespace std;

int ans[max_n + 5] = {1, 1};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= i;
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; i++) {
        sum += ans[i];
    }
    printf("%d\n%d\n", sum, ans[0]);
    return 0;
}
