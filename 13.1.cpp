/*************************************************************************
	> File Name: 13.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月07日 星期三 18时10分09秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char num[55];
int ans[55];

int main() {
    for (int i = 0; i < 100; i++) {
        scanf("%s", num);
        int len = strlen(num);
        if (ans[0] < len) ans[0] = len;
        for (int j = 0; j < len; j++) {
            ans[len - j] += (num[j] - '0');
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10)  continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);//key
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
