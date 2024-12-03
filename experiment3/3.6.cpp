//
// Created by ZhaoHao on 24-11-3.
//

#include<bits//stdc++.h>
using namespace std;
typedef long long ll;
#define ture true
#define flase false

int main() {
    int n;
    cin >> n;
    while (n--) {
        int flag = 0;
        string s;
        cin >> s;
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if (s[i] == ')') {
                if (stk.empty()) {
                    flag = 1;
                    break;
                }
                if (stk.top() == '(')
                    stk.pop();
                else {
                    flag = 1;
                    break;
                }
            } else if (s[i] == ']') {
                if (stk.empty()) {
                    flag = 1;
                    break;
                }
                if (stk.top() == '[')
                    stk.pop();
                else {
                    flag = 1;
                    break;
                }
            } else if (s[i] == '}') {
                if (stk.empty()) {
                    flag = 1;
                    break;
                }
                if (stk.top() == '{')
                    stk.pop();
                else {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1) {
            cout << "No" << endl;
        } else if (stk.empty()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
