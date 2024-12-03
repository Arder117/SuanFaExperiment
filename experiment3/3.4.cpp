//
// Created by ZhaoHao on 24-11-3.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    set<int> a, b, sa, sb;
    int x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        b.insert(x);
    }
    set<int>::iterator it;
    //求交集
    for (it = a.begin(); it != a.end(); it++) {
        if (b.find(*it) != b.end())
            sa.insert(*it);
    }
    //求并集
    for (it = a.begin(); it != a.end(); it++) {
        sb.insert(*it);
    }
    for (it = b.begin(); it != b.end(); it++) {
        sb.insert(*it);
    }
    //输出交集
    cout << sa.size();
    if (sa.size() != 0) {
        for (it = sa.begin(); it != sa.end(); it++)
            cout << " " << *it;
    }
    cout << endl;
    //输出并集
    cout << sb.size();
    if (sb.size() != 0) {
        for (it = sb.begin(); it != sb.end(); it++)
            cout << " " << *it;
    }
    return 0;
}
