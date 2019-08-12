/*************************************************************************
	> File Name: 9.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 19时29分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int a, int b);

int main() {
    int ans = 0;
    for (int n = 1; n < 33; n++) {
        for (int m = n + 1; m < 33; m++) {
            if (gcd(m, n) != 1) continue;
            int a = 2 * m * n;
            int b = m * m - n * n;
            int c = m * m + n * n;
            if (!(1000 % (a + b + c))) {
                int k = 1000 / (a + b + c);
                ans = a * b * c * (int)pow(k, 3);
            }
            if (ans) break;
        }
    }
    printf("%d\n", ans);

    return 0;
}

int gcd(int a, int b) {
    return (b ? (gcd(b, a % b)) : a);
}
