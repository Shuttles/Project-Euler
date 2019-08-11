/*************************************************************************
	> File Name: 14.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月07日 星期三 14时57分51秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#define max_n 1000000
using namespace std;

int  get_len(long long x);

int main() {
    int  num = 0;
    int ans = 0;
    for (int i = 1; i < max_n; i++) {
        if (get_len(i) > ans) ans = get_len(i), num = i;
    }
    printf("%d\n", num);
    return 0;
}

int get_len(long long x) {
    if (x == 1) return 1;
    if(!(x & 1)) return get_len(x / 2) + 1;
    else return get_len(3 * x + 1) + 1;
}
