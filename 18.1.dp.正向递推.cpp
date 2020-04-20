/*************************************************************************
	> File Name: 18.3.dp.另一种状态正向递推.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月15日 星期四 16时28分24秒
 ************************************************************************/
//定义的状态为：dfs(i, j)为从val(0, 0) 到val(i, j)的最大i值
#include <iostream>
#define max_n 15
using namespace std;

int val[max_n + 5][max_n + 5];
int dfs(int i, int j);

int main() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < max_n; i++) {
        val[max_n - 1][i] = dfs(max_n - 1, i);
        if (val[max_n - 1][i] > ans) ans = val[max_n - 1][i];
    }
    cout << ans << endl;
    return 0;
}

int dfs(int i, int j) {
    if (i == 0) return val[0][0];
    int val1 = dfs(i - 1,j);
    int val2 = dfs(i - 1, j - 1);
    return max(val1, val2) + val[i][j];
}

