/*************************************************************************
	> File Name: 5.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 14时57分54秒
 ************************************************************************/

#include <stdio.h>

int gcd(int a, int b);

int main() {
    int ans = 1;
    for (int i = 1; i < 21; i++) {
        if (ans % i == 0) continue;
        ans = ans * i / gcd(ans, i);
    }
    printf("%d\n", ans);
    return 0;
}

int gcd(int a, int b) {
    return (b ? (gcd(b, a % b)) : a);
}
