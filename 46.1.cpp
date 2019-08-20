/*************************************************************************
	> File Name: 46.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 18时55分58秒
 ************************************************************************/

#include<iostream>
#define max_n 100000
using namespace std;

int prime[max_n + 5];
int is_prime[max_n + 5];
void init();
int is_val(int x);
int func(int x);
bool binary_search(int (*func)(int), int l, int r, int x);

int main() {
    init();
    int i;
    for (i = 9; i <= max_n; i += 2) {
        if (!is_prime[i]) continue;
        if (!is_val(i))  {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}

int func(int x) {
    return 2 * x * x;
}

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

bool binary_search(int (*func)(int), int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return true;
    if (func(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(func, l, r, x);
}

int is_val(int x) {
    //x - prime[i] = 2 * n *n;
    for (int i = 1; i <= prime[0] && prime[i] < x; i++) {
        int val = x - prime[i];
        if (binary_search(func, 1, val, val)) return 1;
    }
    return 0;
}
