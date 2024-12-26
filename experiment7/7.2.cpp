//
// Created by ZhaoHao on 24-12-13.
//


// #include <bits/stdc++.h>
// using namespace std;

// // 计算每个数的拆分方式个数
// void dfs(const int n, vector<int> &path, const int sum, int &total) {
//     if (n == 0) {
//         total++;
//         return;
//     }
//
//     for (int i = 1; i <= n; i++) {
//         if (!path.empty() && i < path.back()) {
//             continue;
//         }
//         path.push_back(i);
//         dfs(n - i, path, sum, total);
//         path.pop_back();
//     }
// }
//
// int main() {
//     int total;
//     cin >> total;
//     vector<int> n;
//     for (int i = 0; i < total; i++) {
//         int temp;
//         cin >> temp;
//         n.push_back(temp);
//     }
//
//     const int max_num = *max_element(n.begin(), n.end());
//     vector count(max_num, 0);
//
//     for (int i = 0; i < total; i++) {
//         vector<int> path;
//         int total1 = 0;
//         dfs(n[i], path, n[i], total1);
//         count[n[i]] = total1;
//     }
//
//     for (int i = 0; i < total; i++) {
//         // cout << n[i] << " " << count[n[i]] << endl;
//         cout << count[n[i]] << endl;
//     }
//
//
//     return 0;
// }


// 给定一个自然数N，要求把N拆分成若干个正整数相加的形式，参与加法运算的数可以重复。与“自然数拆分问题”类似，同样需要满足方案的不重复。
// 例如 6 = 3 + 2 和 6 = 2 + 3, 就是重复的拆分方式。 现在需要你求满足条件的拆分有多少种？
// 输入格式:第一行自然整数T，表示之后测试数据组数， 以后T行，每行一个自然数N，（1<N<=4000）
// 注意：本题规模为4000，回溯法还合适吗？仔细思考应该如何设计算法, 建议自行学习完全背包相关知识
// 输出格式: T行，每行输出一个整数，表示拆分的方案数，结果对2147483648取模。
// 输入样例: 在这里给出一组输入。例如：
// 2
// 6
// 7
// 输出样例:在这里给出相应的输出。例如：
// 11
// 15

#include <bits/stdc++.h>
using namespace std;


const int MOD = 2147483648;
const int MAX_N = 4001;

int testCases;
int capacities[MAX_N];
long long dp[MAX_N];

int main() {
    cin >> testCases;

    int maxCapacity = 0;
    for (int i = 0; i < testCases; i++) {
        cin >> capacities[i];
        if (maxCapacity < capacities[i]) {
            maxCapacity = capacities[i];
        }
    }

    dp[0] = 1;

    for (int i = 1; i <= maxCapacity; i++) {
        for (int j = i; j <= maxCapacity; j++) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    for (int i = 0; i < testCases; i++) {
        cout << dp[capacities[i]] << endl;
    }

    return 0;
}
