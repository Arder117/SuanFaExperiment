//
// Created by ZhaoHao on 24-12-13.
//

// 那么什么是一笔画？顾名思义就是一笔可以完成的图。一笔画最基本的要求是在画图的过程中，笔不能离开纸，且笔所画过的线不能重复，最后画完所有的线便算完成。
// 输入格式: 给出图中的节点数N（1<=N<=1000,编号1-N）和边数M；随后M行给出存在边的两个节点的编号。
// 输出格式: 能够一笔画的图输出Y，否则输出N。
// 输入样例1:
// 3 2
// 1 2
// 2 3
// 输出样例1:
// Y


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 1) {
                count++;
            }
        }
        if (count % 2 == 1) {
            flag++;
        }
    }
    if (flag == 0 || flag == 2) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }


    return 0;
}
