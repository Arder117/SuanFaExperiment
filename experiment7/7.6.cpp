//
// Created by ZhaoHao on 24-12-13.
//

// 给定一个有N个顶点和E条边的无向图，顶点从0到N−1编号。请判断给定的两个顶点之间是否有路径存在。如果存在，给出最短路径长度。
// 这里定义顶点到自身的最短路径长度为0。
// 进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。
//
// 输入格式:
// 输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。
// 随后E行，每行给出一条边的两个顶点。每行中的数字之间用1空格分隔。
// 最后一行给出两个顶点编号i，j（0≤i,j<N）,i和j之间用空格分隔。
//
// 输出格式:
// 如果i和j之间存在路径，则输出"The length of the shortest path between i and j is X."，X为最短路径长度，
// 否则输出"There is no path between i and j."。


#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, E;
    cin >> N >> E;
    vector<vector<int> > adj(N + 1);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start, end;
    cin >> start >> end;

    if (start == end) {
        cout << "The length of the shortest path between " << start << " and " << end << " is 0." << endl;
        return 0;
    }

    vector dist(N, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor: adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (neighbor == end) {
                    cout << "The length of the shortest path between " << start << " and " << end << " is " << dist[
                        neighbor] << "." << endl;
                    return 0;
                }
            }
        }
    }

    cout << "There is no path between " << start << " and " << end << "." << endl;
    return 0;
}
