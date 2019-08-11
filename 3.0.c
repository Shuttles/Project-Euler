/*************************************************************************
	> File Name: 3.0.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月01日 星期四 20时55分35秒
 ************************************************************************/
//如果欧拉第三题先打个表，会有多慢？
//事实证明。。。。运行了二十分钟还没出结果。。
#include <stdio.h>
#include <inttypes.h>
#define MAX 10000
#define NUM 600851475143
int64_t prime[NUM + 1] = {0};

int main() {
    int64_t i, j;
    for (i = 2; i * i <= NUM; i++) {
        if (prime[i]) continue;
            for (j = i * i; j <= NUM; j += i) {
                prime[j] = 1;
            }
        }
    for (i = 2; i <= NUM; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
    }
    printf("%" PRId64"\n",prime[prime[0]]);
    return 0;
}
