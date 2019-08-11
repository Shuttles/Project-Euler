/*************************************************************************
	> File Name: 4.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 14时22分34秒
 ************************************************************************/

#include <stdio.h>

int is_val(int x);

int main() {
    int ans = 0;
    for (int a = 100; a < 1000; a++) {
        for (int b = a; b < 1000; b++) {
            if (is_val(a * b) && ans < a * b) {   
                ans = a * b;
                printf("%d * %d = %d\n", a, b, a * b);
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
    return (sum == temp ? 1 : 0);
}
