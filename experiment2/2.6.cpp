//
// Created by ZhaoHao on 24-10-23.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, m = 0;
    int stu[1000000] = {0};
    int search[1000000] = {0};

    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        stu[temp] = temp;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> search[i];
    }

    for (int i = 0; i < m; i++) {
        if (stu[search[i]] == 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}

