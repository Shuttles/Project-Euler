/*************************************************************************
	> File Name: 38.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 14时23分53秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#define max_n 10000
using namespace std;

int digits(int x);
int calc(int x);

int main() {
    int ans = 0;
    for (int i = 1; i < max_n; i++) {
        int temp = calc(i);//生成的这个数一定是九位的完全数
        if (temp > ans)  ans = temp;
    }
    printf("%d\n", ans);
    return 0;
}

int digits(int x) {
    return floor(log10(x)) + 1;
}

int calc(int x) {
    int n = 1;
    int ans = 0;
    while (digits(ans) < 9) {
        ans *= (int)pow(10, digits(x * n));
        ans += x * n;
        n++;
    }
    if (digits(ans) - 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    int temp = ans;
    while (temp) {
        if (num[temp % 10]) return 0;
        num[temp % 10]++;
        temp /= 10;
    }
    return ans;
}
