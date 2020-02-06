/*************************************************************************
	> File Name: 24.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 14时40分24秒
 ************************************************************************/
//核心要义：光哥的代码的核心要义是每向后跳一个数就和后面相应的数字swap，而泽哥的这份代码核心在于在标记数组中从小到大找到没标记的相应需要变换次数的数字
#include<iostream>
using namespace std;
#define max_n 10

int jump_num[max_n + 5];                            //存放的是对应下标数字的阶乘也就是如果这个数字往后+1需要变化几种状态
int dnum[max_n + 5];                                //标记谁用到了谁没用到

void init() {                                       //初始化阶乘数组
    jump_num[0] = 1, dnum[0] = 1;
    for (int i = 1; i < max_n; i++) {
        jump_num[i] = i * jump_num[i - 1];
        dnum[i] = 1;                                //将dnum数组全设为1表示全部没用到
    }
    return ;
}

int get_num(int n, int k) {
    int ind = (k / jump_num[n]);                //ind代表当前数字可以往后走ind-1步
    int i = -1;                                     
    while (ind >= 0) {                              //为了从前往后找当前没有用过的i值是多少（这步很难理解但很重要！！！！）  
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;                                    //标记这个数字用过了
    return i;                                       //返回这个位置变换后的结果
}

int main() {
    init();
    int n, k;
    cin >> n >> k;
    k -= 1; //剩余变换次数
    for (int i = n - 1; i >= 0; i--) {
        int num = get_num(i, k);
        cout << num;
        k %= jump_num[i];//更新剩余变换次数
    }
    cout << endl;
    return 0;
}
