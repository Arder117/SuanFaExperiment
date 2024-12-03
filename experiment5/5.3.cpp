//
// Created by ZhaoHao on 24-11-27.
//

// 输入格式:第一行一个整数T表示有T组测试数据（T<=50）。
// 接下来的T组测试数据：
// 第一行包含两个整数N和M，N表示小明有多少钱，M表示有多少件物品（1<=M<=100）。
// 再二行包含M个整数，表示对应每个物品的价格。
// 第三行包含M个整数，表示小明对每个物品的期待值。
// 其中，小明兜里的钱N、每个物品的价格、每个物品的期待值的值域均为(0, 3000)。
// 输出格式:
// 每组样例一行，输出最大期待值的总和。假设第i组样例最大期待值为e，则输出格式为“Case #i: e”
// 输入样例:
// 4
// 10 5
// 2 3 7 7 3
// 4 3 5 6 4
// 10 8
// 5 6 4 2 3 7 1 8
// 5 3 5 3 5 7 5 7
// 20 7
// 10 15 4 5 6 8 5
// 15 14 9 2 2 6 7
// 10 3
// 7 4 5
// 16 7 10
// 输出样例:
// Case #1: 11
// Case #2: 18
// Case #3: 31
// Case #4: 17


#include<bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    vector<int> ans(T);

    for (int i = 1; i <= T; i++) {
        int N, M;
        cin >> N >> M;
        vector<int> prices(M), values(M);

        for (int j = 0; j < M; j++) {
            cin >> prices[j];
        }
        for (int j = 0; j < M; j++) {
            cin >> values[j];
        }

        vector dp(M + 1, vector(N + 1, 0));
        for (int j = 1; j <= M; j++) {
            for (int k = 1; k <= N; k++) {
                if (prices[j - 1] <= k) {
                    dp[j][k] = max(dp[j - 1][k], dp[j - 1][k - prices[j - 1]] + values[j - 1]);
                } else {
                    dp[j][k] = dp[j - 1][k];
                }
            }
        }
        ans[i - 1] = dp[M][N];
    }

    for (int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": " << ans[i] << endl;
    }

    return 0;
}
