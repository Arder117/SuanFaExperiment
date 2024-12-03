//
// Created by ZhaoHao on 24-11-27.
//

// 把M个弹珠放到N个盘子里面（我们允许有的盘子为空），你能求出有多少种分法吗？（请注意，例如有三个盘子，我们将5,1,1和1,1,5，视为同一种分法）
// 输入格式:输入包含多组测试样例。每组输入的第一行是一个整数t。接下来t行，每行输入两个整数M和N，代表有M个弹珠和N个盘子。（0=<M<=20; 0<N<=20）
// 输出格式:对于每对输入的M和N，输出有多少种方法。
// 输入样例:在这里给出一组输入。
// 例如：
// 1
// 7 3
// 输出样例:在这里给出相应的输出。
// 例如：
// 8

#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= m; i++) {
            dp[i][1] = 1;
        }
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) {
                    dp[i][j] = dp[i - j][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][i];
                }
            }
        }
        cout << dp[m][n] << endl;
    }


    return 0;
}
