//
// Created by ZhaoHao on 24-11-6.
//

// 最大子矩阵和问题。给定m行n列的整数矩阵A，求矩阵A的一个子矩阵，使其元素之和最大。
// 输入格式: 第一行输入矩阵行数m和列数n（1≤m≤100，1≤n≤100），再依次输入m×n个整数。
// 输出格式: 输出第一行为最大子矩阵各元素之和，第二行为子矩阵在整个矩阵中行序号范围与列序号范围。
// 输入样例1:
// 5 6
// 60 3 -65 -92 32 -70
// -41 14 -38 54 2 29
// 69 88 54 -77 -46 -49
// 97 -32 44 29 60 64
// 49 -48 -96 59 -52 25
// 输出样例1:
// 输出第一行321表示子矩阵各元素之和，输出第二行2 4 1 6表示子矩阵的行序号从2到4，列序号从1到6
// 321
// 2 4 1 6

// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> matrix(m, vector<int>(n));
//     for (int i = 0; i < m; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cin >> matrix[i][j];
//         }
//     }
//
// }


#include<bits/stdc++.h>
using namespace std;
int dp[5050][5050];
int m, n, ans = -999999, temp, num;

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            cin >> num;
            dp[i][j] = dp[i - 1][j] + num;
        }
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= i; j++) {
            temp = 0;
            int yy = 1;
            for (int k = 1; k <= n; k++) {
                temp += (dp[i][k] - dp[j - 1][k]);
                if (temp > ans) {
                    ans = temp;
                    x2 = i;
                    y2 = k;
                    x1 = j;
                    y1 = yy;
                }
                if (temp < 0) {
                    temp = 0;
                    yy = k + 1;
                }
            }
        }
    cout << ans << endl;
    cout << x1 << " " << x2 << " " << y1 << " " << y2;
}
