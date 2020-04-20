/*************************************************************************
	> File Name: 18.3.dp另一种状态.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月15日 星期四 16时22分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 15

int val[max_n + 5][max_n + 5];

int main() {
    /*输入*/
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    /*dp逆向实现过程*/
    for (int i = 1; i < max_n; i++) {
        for (int j = 0; j <= i; j++) {
            val[i][j] += max(val[i - 1][j], val[i - 1][j - 1]);
        }
    }
    /*找结果*/
    int ans = 0;
    for (int i = 0; i < max_n; i++) {
        if (val[14][i] > ans) ans = val[14][i];
    }
    cout << ans << endl;
    return 0;
}
