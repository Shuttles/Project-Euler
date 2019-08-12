/*************************************************************************
	> File Name: 44.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 14时46分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cinttypes>
using namespace std;

int64_t pentagonal_number(int64_t n);
int64_t is_pentagonal_number(int64_t x);

int main() {
    int64_t i = 1, j = 1, ans = INT32_MAX;
    while (pentagonal_number(j + 1) - pentagonal_number(j) < ans) {    //隐含上界
        for (i = j - 1; i >= 1 && pentagonal_number(j) - pentagonal_number(i) < ans; i--) { 
            if (!is_pentagonal_number(pentagonal_number(j) + pentagonal_number(i))) continue;
            if (!is_pentagonal_number(pentagonal_number(j) - pentagonal_number(i))) continue; 
            if (pentagonal_number(j) - pentagonal_number(i) >= ans) continue;
            //printf("pen(j) = " "%" PRId64 "  "   "pen(i) = " "%" PRId64 "\n",pentagonal_number(j), pentagonal_number(i));
            ans = pentagonal_number(j) - pentagonal_number(i);
           } 
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}

int64_t pentagonal_number(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t is_pentagonal_number(int64_t x) {
    int64_t head = 1, tail = x, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (pentagonal_number(mid) == x) return mid;
        if (pentagonal_number(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}
