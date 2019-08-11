/*************************************************************************
	> File Name: 36.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 18时52分52秒
 ************************************************************************/

#include<iostream>
#define max_n 1000000
using namespace std;

int is_val(int x);
int is_val1(int x);
int is_val2(int x);

int main() {
    int sum = 1;
    for (int i = 3; i < max_n; i++) {
        if (is_val(i)) sum += i;
    }
    cout << sum << endl;
    return 0;
}

int is_val1(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return temp == sum;
}

int is_val2(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum = sum * 2 + x % 2;
        x /= 2;
    }
    return temp == sum;
}

int is_val(int x) {
    if (is_val1(x) && is_val2(x))
        return 1;
    else return 0;
}
