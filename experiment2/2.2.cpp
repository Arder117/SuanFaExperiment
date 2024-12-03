//
// Created by ZhaoHao on 24-10-23.
//

// 已知斐波那契数列F,求解该数列的第n项，结果对998244353取模。

#include <bits//stdc++.h>
using namespace std;

int Fibonacci(int n) {
    int a = 0, b = 1, c=0;
    for (int i = 1; i <= n; i++) {
        a = (b+c) % 998244353;
        b = c;
        c = a;
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    cout << Fibonacci(n) << endl;
    return 0;
}
