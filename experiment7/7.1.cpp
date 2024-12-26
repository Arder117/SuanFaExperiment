//
// Created by ZhaoHao on 24-12-13.
//

// 一个整数N(N > 1)可以拆分成若干个大于等于1的自然数之和，请你输出所有不重复的拆分方式。
// 例如：输入6, 输出6=1+1+1+1+1+1

#include <bits/stdc++.h>
using namespace std;

void dfs(const int n, vector<int> &path, const int sum) {
    if (n == 0) {
        cout << sum << "=";
        for (int i = 0; i < path.size(); i++) {
            if (i != path.size() - 1) {
                cout << path[i] << "+";
            } else {
                cout << path[i] << endl;
            }
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!path.empty() && i < path.back()) {
            continue;
        }
        path.push_back(i);
        dfs(n - i, path, sum);
        path.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> path;
    dfs(n, path, n);
    return 0;
}