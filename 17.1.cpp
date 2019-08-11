/*************************************************************************
	> File Name: 17.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月07日 星期三 16时19分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int get_letter(int x);

int arr1[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
                6, 6, 8, 8, 7, 7, 9, 8, 8};

int arr2[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        sum += get_letter(i);
    }
    printf("%d\n", sum + 3 + 8);

    return 0;
}

int get_letter(int x) {
    if (x < 20) return arr1[x];
    if (x < 100) return arr2[x / 10] + arr1[x % 10];
    if (x < 1000) {
        if (!(x % 100)) return arr1[x / 100] + 7;
        return arr1[x / 100] + get_letter(x % 100) + 10;
    }
}
