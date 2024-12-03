//
// Created by ZhaoHao on 24-12-4.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> distances(k + 2);
    distances[0] = 0;
    for (int i = 1; i < k + 2; i++) {
        cin >> distances[i];
    }

    int current_fuel = n;
    int refuel_count = 0;
    for (int i = 1; i < k + 2; i++) {
        if (n < distances[i] || current_fuel < distances[i]) {
            cout << "No Solution!" << endl;
            return 0;
        }
        current_fuel -= distances[i];
        if (current_fuel < distances[i + 1]) {
            refuel_count++;
            current_fuel = n;
        }
    }

    cout << refuel_count << endl;

    return 0;
}
