/*************************************************************************
	> File Name: 3.1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月01日 星期四 20时48分21秒
 ************************************************************************/
//启发：利用了数论中的一些结论，感觉很神奇
#include <stdio.h>
#include <inttypes.h>
#define NUM 600851475143

int main() {
    int64_t last_prime = 0;
    int64_t num = NUM;
    int64_t i;
    for (i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            num /= i;
            last_prime = i;
        }
    }
    if (num != 1) last_prime = num;
    printf("%"PRId64"\n", last_prime);
    return 0;
}
