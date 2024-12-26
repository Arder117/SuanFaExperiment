//
// Created by ZhaoHao on 24-12-13.
//

// 森林可以用N乘M的网格表示。让我们用“.”标记空旷的草地，中间有一棵树，中间有“+”，维吉科斯拉夫的当前位置是“V”，他的小屋的位置是“J”。
// Vjekoslav可以从当前的补丁运行到任何其他补丁北部，东部，南部或西部从他，即使它包含一棵树。
// 如果Vjekoslav站在网格的第R行和第C列，并且在第a行和第B列中有一棵树，那么Vjekoslav和该树之间的距离为：∣R−A∣+∣C−B∣
// 帮助Vjekoslav找到通往他的小屋的最佳路线。最佳路线是在任何给定时刻使Vjekoslav和所有树之间的最小距离最大化的任何路线。
// 请注意，Vjekoslav的小屋并不占据整个地块，因此该地块也必须包含在路线中。
// 输入格式: 第一行输入包含整数N和M（1≤N、M≤500），表示网格尺寸。接下来的N行包含M个字符：'.', '+', 'V', 'J' 输入将只包含一个字符“V”和“J”，
// 以及至少一个字符“+”。
// 输出格式:输出一个整数，即在最佳路径中与树的最小距离
// 输入样例1:
// 4 4
// +...
// ....
// ....
// V..J
// 输出样例1:
// 3


#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1003;
int graph[MAXN][MAXN];
int visitedEdges[MAXN][MAXN];
int n, m;
set<int> vertices;
int foundPath = 0;

void dfs(int node, int edgeCount) {
    for (int i = 1; i <= n; i++) {
        if (foundPath == 1) break;
        if (graph[node][i] == 1 && visitedEdges[node][i] == 0 && visitedEdges[i][node] == 0) {
            visitedEdges[node][i] = 1;
            visitedEdges[i][node] = 1;
            if (edgeCount + 1 == m) {
                foundPath = 1;
                cout << "Y" << endl;
                exit(0);
            }
            dfs(i, edgeCount + 1);
            visitedEdges[node][i] = 0;
            visitedEdges[i][node] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    if (n == 1 && m == 0) {
        cout << "Y" << endl;
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        vertices.insert(x);
        vertices.insert(y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    if (vertices.size() != n) {
        cout << "N" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        fill(&visitedEdges[0][0], &visitedEdges[0][0] + sizeof(visitedEdges) / sizeof(visitedEdges[0][0]), 0);
        foundPath = 0;
        dfs(i, 0);
        if (foundPath == 1) break;
    }
    if (foundPath == 0) cout << "N" << endl;
    return 0;
}
