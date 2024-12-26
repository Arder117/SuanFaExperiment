//
// Created by ZhaoHao on 24-12-13.
//

// 幸福小镇可以划分为N个小小镇，从1到N编号！这些小小镇由N-1条道路连通，我们把每条道路的长度简化为1！只要在每个小小镇增派人手，就可以让小镇的治安情况变得越来越好！（题目保证两个小镇之间的道路只有一条！）
// 每次小Z会询问你两个小小镇的编号，请你计算出这两个小镇之间的最短路径长度！
// 输入格式:第一行包含一个正整数（N<=1000），表示小小镇的个数！接下来N-1行，每行包含两个1到N之间的整数，表示这两个编号的小小镇之间有一条路！
// 接下来一行包含一个整数q（q<=100)，表示询问数！接下来q行，每行包含两个小小镇的编号，请在一行中输出这两个小小镇的最短路径长度！
// 输出格式:输出答案即可！
// 输入样例:在这里给出一组输入。例如：
// 10
// 1 2
// 2 3
// 1 4
// 4 5
// 4 6
// 3 7
// 3 8
// 1 9
// 9 10
// 5
// 3 8
// 9 3
// 1 1
// 1 7
// 1 9
// 输出样例: 在这里给出相应的输出。例如：
// 1
// 3
// 0
// 3
// 1


#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector graph(n, vector(n, 0));
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queue<int> q;
        q.push(a - 1);
        vector visited(n, 0);
        visited[a - 1] = 1;
        while (!q.empty()) {
            const int temp = q.front();
            q.pop();
            for (int j = 0; j < n; j++) {
                if (graph[temp][j] == 1 && visited[j] == 0) {
                    q.push(j);
                    visited[j] = visited[temp] + 1;
                }
            }
        }
        cout << visited[b - 1] - 1 << endl;
    }

    return 0;
}
