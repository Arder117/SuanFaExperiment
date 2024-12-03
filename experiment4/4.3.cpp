//
// Created by ZhaoHao on 24-11-6.
//
// 设计一个O(n2)时间的算法，找出由n个数组成的序列的最长单调递增子序列。
// 输入格式:输入有两行：第一行：n，代表要输入的数列的个数, 第二行：n个数，数字之间用空格格开
// 输出格式: 最长单调递增子序列的长度
// 输入样例:在这里给出一组输入。例如：
// 5
// 1 3 5 2 9
// 输出样例:
// 在这里给出相应的输出。
// 例如：4

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
//     vector<int> dp(n, 1);
//     for (int i = 1; i < n; ++i) {
//         for (int j = 0; j < i; ++j) {
//             if (nums[i] > nums[j]) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }
//     cout << *max_element(dp.begin(), dp.end()) << endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b[0] = 1;

    for (int i = 1; i < n; ++i) {
        int max = 0;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                if (max < b[j]) {
                    max = b[j];
                }
            }
        }
        b[i] = max + 1;
    }

    int length = 0, l = 0;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > length) {
            length = b[i];
            k = i;
            l = length;
        }
    }

    const auto LIS = static_cast<int *>(malloc(sizeof(int) * length));
    LIS[--length] = a[k];
    for (int i = k; i >= 0; i--) {
        if (a[i] < a[k] && b[i] == b[k] - 1) {
            LIS[--length] = a[i];
            k = i;
        }
    }
    cout << l << endl;

    return 0;
}
