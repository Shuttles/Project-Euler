/*************************************************************************
	> File Name: 28.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 15时37分54秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int sum = 1;
    for (int i = 3; i <= 1001; i += 2) {
        sum += 4 * i * i - 6 * i + 6;
    }
    printf("%d\n", sum);
    return 0;
}
