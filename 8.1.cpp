/*************************************************************************
	> File Name: 8.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 18时27分44秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include "EP08.h"

int main() {
    int64_t ans = 1, zero = 0, ans_max = 0;
    for (int i = 0; num[i]; i++) {
        if (num[i] = '0') {
            zero++;
        } else {
            ans *= (num[i] - '0');
        }
        if (i >= 13) {
            if (num[i - 13] == '0') {
                zero--;
            } else {
                ans /= (num[i - 13] - '0');
            }
        }
        if (zero == 0 && ans > ans_max) ans_max = ans;
    }
    printf("%"PRId64"\n", ans_max);
    return 0;
}
