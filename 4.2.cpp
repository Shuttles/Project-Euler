/*************************************************************************
	> File Name: 4.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 14时32分53秒
 ************************************************************************/

#include <stdio.h>

int is_val(int x);

int main() {
    int ans = 0;
    for (int a = 100; a < 1000; a++) {
        for (int b = ans / a + 1; b <= a; b++) {
            if (is_val(a * b) && ans < a * b) {
                ans = a * b;
                printf("%d * %d = %d\n", a, b, ans);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

int is_val(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return temp == sum;
}
