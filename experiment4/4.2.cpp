//
// Created by ZhaoHao on 24-11-6.
//

// 现在给你两个由AGCT四个字母构成的字符串，请你求出两个DNA序列的最长公共子序列。
// 输入格式: 两行，每行一个字符串，分别表示一个DNA序列（每个字符串长度不超过1000）。
// 输出格式: 一个数，最长公共子序列元素的个数。
// 输入样例:在这里给出一组输入。 例如：
// AGCT
// ATT
// 输出样例: 在这里给出相应的输出。例如： 2

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[len1][len2] << endl;

    return 0;
}
