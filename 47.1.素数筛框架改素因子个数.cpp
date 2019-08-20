/*************************************************************************
	> File Name: 47.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 19时56分15秒
 ************************************************************************/

#include <iostream>
#define max_n 1000000
using namespace std;

int prime[max_n + 5];
void init();

int main() {
    init();
    for (int i = 2; i < 100; i++) {
        cout << i << " = " << prime[i] << endl;
    }
    for (int i = 2; i < max_n; i++) {
        int flag = 1;
        for (int k = 0; k < 4 && flag; k++) {
            flag = (prime[i + k] == 4);
        }
        if (flag) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i]) continue;
        for (int j = i ; j <= max_n; j += i) {
            prime[j] += 1;
        }
    }
    return ;
}
