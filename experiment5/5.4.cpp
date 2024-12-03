//
// Created by ZhaoHao on 24-11-27.
//
// 有N堆石子排成一排(n<=100),现要将石子有次序地合并成一堆，规定每次只能选相邻的两堆合并成一堆，并将新的一堆的石子数，记为该次合并的得分，
// 编一程序，给出堆数n及每堆石子数(<=200)；
// （1）选择一种合并石子的方案，使得做n-1次合并，得分的总和最少
// （2）选择一种合并石子的方案，使得做n-1次合并，得分的总和最多
// 输入格式: 第一行为石子堆数n, 第二行为每堆石子数，每两个数之间用一空格分隔。
// 输出格式: 第一行为最小合并得分，第二行是最大的合并得分。
// 输入样例: 在这里给出一组输入。例如：
// 4
// 4 5 9 4
// 输出样例: 在这里给出相应的输出。例如：
// 44
// 54

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> stones(n + 1);
    stones[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> stones[i];
    }
    int minScore = 0, maxScore = 0;


    vector dp(n + 1, vector(n + 1, 0));
    vector dp1(n + 1, vector(n + 1, 0));
    vector sum(n + 1, vector(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        dp1[i][i] = 0;
        sum[i][i] = stones[i];
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                sum[i][j] += stones[k];
            }
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[i][j]);
            }
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp1[i][j] = INT_MIN;
            for (int k = i; k < j; k++) {
                dp1[i][j] = max(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + sum[i][j]);
            }
        }
    }

    minScore = dp[1][n];
    maxScore = dp1[1][n];
    cout << minScore << endl;
    cout << maxScore << endl;
    return 0;
}
