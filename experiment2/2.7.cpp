//
// Created by ZhaoHao on 24-10-23.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    int res = 0;
    int x[10001] = {0}, y[10001] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    sort(x, x + n);
    for (int i = 0; i < n; i++)
        x[i] = x[i] - i;
    sort(x, x + n);
    sort(y, y + n);
    for (int i = 0; i < n; i++) {
        res += abs(y[i] - y[n / 2]);
        res += abs(x[i] - x[n / 2]);
    }
    cout << res << endl;
    return 0;
}
