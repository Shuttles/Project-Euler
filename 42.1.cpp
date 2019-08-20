/*************************************************************************
	> File Name: 42.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 18时23分06秒
 ************************************************************************/

#include <iostream>
#include "input42.h"
using namespace std;

bool binary_search(int (*func)(int), int l, int r, int x);
int triangle_number(int n);
int is_val(char *str);

int main() {
    int n = sizeof(name) / 100, cnt = 0;                      //骚操作啊
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        if (is_val(name[i])) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

int triangle_number(int n) {
    return n * (n + 1) / 2;
}
bool binary_search(int (*func)(int), int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return true;
    if (func(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(func, l, r, x);
}

int is_val(char *str) {
    int sum = 0;
    for (int i = 0; str[i]; i++) {
        sum += (str[i] - 'A' + 1);//一定注意要+1！！！！
    }
    if (binary_search(triangle_number, 1, sum, sum)) return 1;
    return 0;
}
