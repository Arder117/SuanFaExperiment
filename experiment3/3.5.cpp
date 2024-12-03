//
// Created by ZhaoHao on 24-11-3.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int t, n;
    map<string, int> m;
    map<string, int>::iterator it;
    cin >> t;
    while (t--) {
        cin >> n;
        m.clear();
        while (n--) {
            cin >> s;
            m[s]++;
        }
        for (it = m.begin(); it != m.end(); it++)
            cout << it->first << " " << it->second << endl;
    }
    return 0;
}
