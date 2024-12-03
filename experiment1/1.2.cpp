//
// Created by ZhaoHao on 24-10-30.
//

#include <bits//stdc++.h>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n;
    if (n == 10)
        m = 1 / n;
    else
        m = n;
    // .1f表示保留一位小数
    printf("f(%.1f) = %.1f", n,m);
}
