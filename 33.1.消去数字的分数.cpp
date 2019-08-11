/*************************************************************************
	> File Name: 33.1.消去数字的分数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 16时41分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

int up[5];
int down[5];

int gcd(int a, int b);

int main() {
    int a, b;
    int i = 1, j = 1;
    for (a = 10; a < 100; a++) {
        for (b = a + 1; b < 100; b++) {
            if (!(a % 10) || !(b % 10)) continue;
            int x1 = a / 10;
            int y1 = a % 10;
            int x2 = b / 10;
            int y2 = b % 10;
            if (x1 == y2) {
                if (a * x2 == b * y1) {
                    up[i] = x1 * y1;
                    down[i] = x2 * y2;
                    i++;
                }        
            }
            if (x2 == y1) {
                if (a * y2 == b * x1) {
                    up[i] = x1 * y1;
                    down[i] = x2 * y2;
                    i++;
                }
            }
        }
    }
    int x;
    x = (down[1] * down[2] * down[3] * down[4]);
    int y;
    y = (up[1] * up[2] * up[3] * up[4]);
    int ans;
    ans = x / gcd(x,y);
    printf("%d\n", ans);
    return 0;
}

int gcd(int a, int b) {
    return (b ? (gcd(b, a % b)) : a);
}
