/*************************************************************************
	> File Name: 6.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 14时48分46秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int sum1= 0, sum2 = 0;
    for (int i = 1; i < 101; i++) {
        sum1 += i;
        sum2 += i * i;
    }
    printf("%d\n", sum1 * sum1 - sum2);

    return 0;
}
