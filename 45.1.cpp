/*************************************************************************
	> File Name: 45.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 18时39分07秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cinttypes>
using namespace std;

int64_t Triangle_number(int64_t x);
int64_t Pentagonal_number(int64_t x);
int64_t Hexagonal_number(int64_t x);
int64_t binary_search(int64_t (*f)(int64_t), int64_t x);

int main() {
    int64_t n = 144;
    while (1) {
        if (binary_search(Pentagonal_number, Hexagonal_number(n))) {
            printf("%" PRId64 "\n", Hexagonal_number(n));
            return 0;
        }
        n++;
    }
    return 0;
}

int64_t Pentagonal_number(int64_t n) {
    return (3 * n - 1) * n / 2;
}
int64_t Hexagonal_number(int64_t n) {
    return n * (2 * n - 1);
}

int64_t binary_search(int64_t (*f)(int64_t),int64_t x) {
    int64_t head = 1, tail = x, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (f(mid) == x) return mid;
        if (f(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int64_t Triangle_number(int64_t n) {
    return n * (n + 1) / 2;
}
