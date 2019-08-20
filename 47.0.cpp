/*************************************************************************
	> File Name: 47.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 19时31分56秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 100000

int prime[max_n + 5];
void init();
int biggest_prime(int x);
int is_val(int n);

int main() {
    init();
    int n = 645;
    while (1) {
        if (is_val(n)) {
            printf("%d\n", n);
            return 0;
        }
        n++;
    }
    return 0;
}

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int biggest_prime(int x) {
    int ans = 0;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) x /= i;
    }
    if (x != 1) ans = x;
    return ans;
}

int is_val(int n) {
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt0 = 0;
    if (biggest_prime(n) == biggest_prime(n + 1) || biggest_prime(n) == biggest_prime(n + 2) || biggest_prime(n) == biggest_prime(n + 3) || biggest_prime(n + 1) == biggest_prime(n + 2) || biggest_prime(n + 1) == biggest_prime(n + 3) || biggest_prime(n + 2) == biggest_prime(n + 3)) return 0;
    n /= biggest_prime(n), cnt0++;
    (n + 1) /= biggest_prime(n + 1), cnt1++;
    (n + 2) /= biggest_prime(n + 2), cnt2++;
    (n + 3) /= biggest_prime(n + 3), cnt3++;

}
