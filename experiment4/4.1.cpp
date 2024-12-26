//
// Created by ZhaoHao on 24-11-6.
//

//给定一个由 n行数字组成的数字三角形如下图所示。试设计一个算法，计算出从三角形
//的顶至底的一条路径 (每一步可沿左斜线向下或右斜线向下)，使该路径经过的数字总和最大。
// 输入格式: 输入有n+1行：第 1 行是数字三角形的行数 n，1<=n<=100。接下来 n行是数字三角形各行中的数字。所有数字在0..99 之间。
// 输出格式:输出最大路径的值。


#include <bits/stdc++.h>
using namespace std;

int main() {
    //输入
    int n;
    cin >> n;
    vector triangle(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    //动态规划
    vector dp(n, vector<int>(n));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    int max_sum = *max_element(dp[n - 1].begin(), dp[n - 1].end());

    cout << max_sum << endl;

    return 0;
}
