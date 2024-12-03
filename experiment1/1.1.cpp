//
// Created by ZhaoHao on 24-10-30.
//

// 本题要求编写程序，输出整数152的个位数字、十位数字和百位数字的值。
// 152 = 个位数字 + 十位数字*10 + 百位数字*100

#include <bits//stdc++.h>
using namespace std;

int main() {
    int num = 152;
    int a = num % 10; // 个位数字
    int b = (num / 10) % 10; // 十位数字
    int c = num / 100; // 百位数字
    cout << num << " = " << a << " + " << b << "*10" << " + " << c << "*100" << endl;
    return 0;
}