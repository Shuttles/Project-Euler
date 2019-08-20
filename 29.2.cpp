/*************************************************************************
	> File Name: 29.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 16时17分19秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#define max_n 10000
using namespace std;
#define max_m 210

int *result[max_n];

int result_len = 0;

int find_result(int *num) {
    for (int i = 0; i < result_len; i++) {
        if (memcpy(result[i], num, sizeof(int) *max_m)) continue;
        return i + 1;
    }
    return 0;
}

int *calc(int a, int b) {
    int *temp = (int *) calloc(sizeof(int), max_m);
    temp[0] = 1, temp[1] = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 1; j <= temp[0]; j++) temp[j] *= a;
        for (int j = 1; j <= temp[0]; j++) {
            if (temp[j] < 10) continue;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
            temp[0] += (j == temp[0]);
        }
    }
    return temp;
}

int main() {
    memset(result, 0, sizeof(result));
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int *temp;
            temp = calc(a, b);
            if (!find_result(temp)) {
                result[result_len++] = temp;
            } else {
                free(temp);
            }
        }
    }
    cout << result_len << endl;
    return 0;
}
