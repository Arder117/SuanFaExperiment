//
// Created by ZhaoHao on 24-11-27.
//
// 小明经常玩一个矩阵取数游戏：对于一个给定的n x n的矩阵，矩阵中的每个元素aij表示该格子的价值，均为非负整数。游戏规则如下：
// 小明从左上角走到右下角，只能向下向右走，经过某个格子，就能获得格子相应价值的奖励，
// 请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大奖励值。
// 输入格式: 输入包括n+1行：第1行为一个整数n。(2 <= n <= 500),第2~n+1行为nxn矩阵，其中每行有n个用单个空格隔开的非负整数。（0 <= aij <= 10000)
// 输出格式:仅包含1行，为一个整数，即输入矩阵取数后的最大得分
// 输入样例:在这里给出一组输入。例如：
// 3
// 1 3 3
// 2 1 3
// 2 2 1
// 输出样例:在这里给出相应的输出。例如：
// 11

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    vector dp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = a[i][j];
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + a[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
