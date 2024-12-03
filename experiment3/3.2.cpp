//
// Created by ZhaoHao on 24-11-3.
//

#include <bits//stdc++.h>
using namespace std;

int main() {
    int n;
    string s, name;
    cin >> n;
    list<string> l;
    while (n--) {
        cin >> s;
        if (s == "in") {
            cin >> name;
            l.push_back(name);
        } else if (s == "out") {
            l.pop_front();
        } else if (s == "q") {
            if (l.empty()) {
                cout << "NULL" << endl;
            } else {
                cout << l.front() << endl;
            }
        }
    }

    return 0;
}
