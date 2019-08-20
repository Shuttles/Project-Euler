/*************************************************************************
	> File Name: 12.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月18日 星期日 17时18分41秒
 ************************************************************************/

#include <iostream>
using namespace std;

int sum(int num);
int triangle_number(int n);

int main() {
    int n = 2;
    int fmax = 0;
    while (1) {
        if (n & 1) {
            fmax = sum(n) * sum((n + 1) / 2);
        } else {
            fmax = sum(n / 2) * sum(n + 1);
        }
        if (fmax > 500) break;
        n++;
    }
    printf("%d\n", triangle_number(n));
    return 0;
}

int triangle_number(int n) {
    return n * (n + 1) / 2;
}

int sum(int num) {
    int ans = 1;
    for (int i = 2; i * i <= num; i++) {
        int cnt = 0;
        if (num % i == 0) {
            while (num % i == 0) {
                num /= i;
                cnt++;
            }
            ans *= (cnt + 1);
        }
    }
    if (num != 1) ans *= 2;
    return ans;
}
