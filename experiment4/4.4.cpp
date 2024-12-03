//
// Created by ZhaoHao on 24-11-6.
//

// 给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n]，求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值。
// 当所给的整数均为负数时，定义子段和为0。要求算法的时间复杂度为O(n)。
// 输入格式: 输入有两行：第一行是n值（1<=n<=10000)；第二行是n个整数。
// 输出格式: 输出最大子段和。
// 输入样例: 在这里给出一组输入。例如：
// 6
// -2 11 -4 13 -5 -2
// 输出样例: 在这里给出相应的输出。例如：
// 20

// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//     }
//
//
//
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int s[n] = {};
    int flag = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) flag++;
    }

    if (flag == n) cout << 0;
    else {
        s[0] = a[0];
        for (int i = 1; i < n; i++) {
            if (s[i - 1] <= 0) s[i] = a[i];
            else s[i] = s[i - 1] + a[i];
        }
        int max = s[0];
        for (int i = 0; i < n; i++) {
            if (max < s[i]) max = s[i];
        }
        cout << max;
    }
}
