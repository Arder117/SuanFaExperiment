#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<pair<int, int> > machines(n);
        vector<pair<int, int> > tasks(m);

        for (int i = 0; i < n; ++i) {
            cin >> machines[i].first >> machines[i].second;
        }

        for (int i = 0; i < m; ++i) {
            cin >> tasks[i].first >> tasks[i].second;
        }

        sort(machines.begin(), machines.end(), [](auto a, auto b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        });

        sort(tasks.begin(), tasks.end(), [](auto a, auto b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        });

        int count = 0;
        long money = 0;

        vector machine(105, 0);

        for (int i = 0, j = 0; i < m; i++) {
            while (j < n && machines[j].first >= tasks[i].first) {
                machine[machines[j].second]++;
                j++;
            }
            for (auto k = tasks[i].second; k <= 100; k++) {
                if (machine[k]) {
                    machine[k]--;
                    money += tasks[i].first * 500 + tasks[i].second * 2;
                    count++;
                    break;
                }
            }
        }

        cout << count << " " << money << endl;
    }
    return 0;
}

