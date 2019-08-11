/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 14时51分12秒
 ************************************************************************/
//该算法的时间复杂度为Ｏ(n)
#include <iostream>
#include <cinttypes>
using namespace std;

int is_val(int x);

int main() {
    int64_t sum = 0;
    for (int i = 3; i < 1000000000; i++) {
        if (is_val(i)) sum += i;
    }    
    cout << sum << endl;
    return 0;
}

int is_val(int x) {
    if (!(x % 3) || !(x % 5)) return 1;
    return 0;
}
