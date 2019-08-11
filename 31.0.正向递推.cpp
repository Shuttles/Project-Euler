/*************************************************************************
	> File Name: 31.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月11日 星期日 19时43分32秒
 ************************************************************************/
 //正向递推：公式怎么写就怎么写程序,公式:f(k, n) = f(k - 1, n) + f(k, n - w[k]);
//这种方法用递归，如果不加记忆化。时间是0.022s，
//加了记忆化之后，时间是0.001s
#include <iostream>
#include <cstdio>
int w[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
int f(int k, int n);
int keep[9][205];

int main() {
    printf("%d\n", f(8, 200));
    return 0;
}

int f(int k, int n) {
    if (n == 0) return 1;
    if (n < 0 || k <= 0) return 0;
    if (keep[k][n]) return keep[k][n];
    int temp = f(k - 1, n) + f(k, n - w[k]);
    if ((k > 0 && k < 9) && (n >= 0 && n <= 200))
        keep[k][n] = temp;
    return temp;
}
