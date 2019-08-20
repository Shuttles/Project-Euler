/*************************************************************************
	> File Name: 21.0.因子和.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 14时12分26秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define max_n 1000000

int sum_of_divisors[max_n + 5] = {0};
void get_divisors(int x);

int main() {
    int sum = 0;
    for (int i = 1; i < max_n; i++) {
        get_divisors(i);
        sum_of_divisors[i] -= i;
        printf("sum_of_divisors[%d] = %d\n", i,  sum_of_divisors[i]);
    }
    for (int i = 1; (i < max_n); i++) {
        if (sum_of_divisors[i] < max_n && (sum_of_divisors[sum_of_divisors[i]] == i) && (i != sum_of_divisors[i])) {
            sum += i;
            printf("i = %d sum_of_divisors = %d\n", i, sum_of_divisors[i]);
        }
    }
    printf("%d\n", sum);
    return 0;
}

void get_divisors(int x) {
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            sum_of_divisors[x] += i + x / i;
        }
    }
    return;
}
