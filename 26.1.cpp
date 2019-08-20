/*************************************************************************
	> File Name: 26.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 15时56分04秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define max_n 1000

int keep[max_n + 5];

int get_len(int x);

int main() {
    int value = 0, len = 0;
    for (int i = 1; i < max_n; i++) {
        int temp = get_len(i);
        if (temp > len) len = temp, value = i;
    }
    cout << value << " " << len << endl;
    return 0;
}

int get_len(int x) {
    memset(keep, 0, sizeof(keep));
    int remainder = 1, t = 1;
    keep[1] = 1; 
    while (remainder) {
        remainder *= 10;
        remainder %= x;
        t++;
        if (keep[remainder]) return t - keep[remainder];
        keep[remainder] = t;
    }
    return 0;
}
