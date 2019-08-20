/*************************************************************************
	> File Name: 24.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 14时40分24秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 10

int jump_num[max_n + 5];
int dnum[max_n + 5];

void init() {                                       //初始化阶乘数组
    jump_num[0] = 1, dnum[0] = 1;
    for (int i = 1; i < max_n; i++) {
        jump_num[i] = i * jump_num[i - 1];
        dnum[i] = 1;                                //将dnum数组全设为1
    }
    return ;
}

int get_num(int n, int k) {
    int ind = (k / jump_num[n]) + 1;
    int i = -1;
    while (ind > 0) {
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}

int main() {
    init();
    int n, k;
    cin >> n >> k;
    k -= 1;
    for (int i = n - 1; i >= 0; i--) {
        int num = get_num(i, k);
        cout << num;
        k %= jump_num[i];
    }
    return 0;
}
