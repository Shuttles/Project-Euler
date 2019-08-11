/*************************************************************************
	> File Name: 1.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 14时59分57秒
 ************************************************************************/
 //该方法时间复杂度为o(1)

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int sum3 = (3 + 999) * 333 / 2;
    int sum5 = (5 + 995) * 199 / 2;
    int sum15 = (15 + (1000 / 15) * 15) * (1000 / 15) / 2;
    printf("%d\n", sum3 + sum5 -sum15);
    return 0;
}
