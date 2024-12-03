//
// Created by ZhaoHao on 24-10-23.
//

// 给定一个长度为n的非负序列A，请你找出一个长度不小于L的子段（子段是序列A中一些连续的元素构成的集合），使得子段中数值的平均值最大。最终输出这个最大的平均值。
// 输入格式: 第一行两个整数n, L(1 <= L <= n <= 100000)以下n行，每行一个非负整数，表示序列A中每个元素的值。
// 输出格式: 一个整数，欲求的最大平均值乘以1000后的结果（注意不要四舍五入，直接输出）。

// #include<bits/stdc++.h>
// using namespace std;

// // 递归法，从L, L+1,...,n-1中找出最大值
// int FindMaxAverage(int a[], int n, int L) {
//     // 递归终止条件
//     if (L == n) {
//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             sum += a[i];
//         }
//         return sum / L;
//     }
//
//     // 递归调用,比较L和L+1的平均值,返回较大的
//     return FindMaxAverage(a, n, L + 1) > FindMaxAverage(a, n - 1, L)
//                ? FindMaxAverage(a, n, L + 1)
//                : FindMaxAverage(a, n - 1, L);
// }
//
// int main(int argc, char *argv[]) {
//     int n, L;
//     cin >> n >> L;
//     int a[100000];
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     cout << FindMaxAverage(a, n, L) * 1000;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int n = 0, L = 0;
double elements[100001] = {0};
double maxElement = 0, minElement = 1e9;

void myRead() {
    cin >> n >> L;
    for (int i = 1; i <= n; ++i) {
        cin >> elements[i];
        maxElement = max(elements[i], maxElement);
        minElement = min(elements[i], minElement);
    }
}

bool myCheck(double average) {
    bool flag = false;

    double sum[100001] = {0};
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + (elements[i] - average);
    }

    double fronts = 1e9;
    for (int i = L; i <= n; ++i) {
        fronts = min(fronts, sum[i - L]);
        if (sum[i] - fronts > 0) {
            flag = true;
            break;
        }
    }

    return flag;
}

int main() {
    myRead();

    double low = minElement, high = maxElement, answer = (low + high) / 2;
    while (high - low > 1e-5) {
        if (myCheck(answer)) {
            low = answer;
        } else {
            high = answer;
        }

        answer = (low + high) / 2;
    }

    cout << (int) (high * 1000);

    return 0;
}
