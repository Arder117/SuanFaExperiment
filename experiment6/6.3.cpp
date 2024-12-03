//
// Created by ZhaoHao on 24-12-4.
//
// 假设要在足够多的会场里安排一批活动，并希望使用尽可能少的会场。设计一个有效的贪心算法进行安排。（这个问题实际上是著名的图着色问题。
// 若将每一个活动作为图的一个顶点，不相容活动间用边相连。使相邻顶点着有不同颜色的最小着色数，相应于要找的最小会场数。）
// 输入格式:第一行有 1 个正整数k，表示有 k个待安排的活动。接下来的 k行中，每行有 2个正整数，分别表示 k个待安排的活动开始时间和结束时间。
// 时间以 0 点开始的分钟计。
// 输出格式:输出最少会场数。
// 输入样例:
// 5
// 1 23
// 12 28
// 25 35
// 27 80
// 36 50
// 输出样例: 在这里给出相应的输出。例如：
// 3


#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<tuple<int, int, bool> > activities(k);
    for (int i = 0; i < k; i++) {
        cin >> get<0>(activities[i]) >> get<1>(activities[i]);
        get<2>(activities[i]) = false;
    }

    sort(activities.begin(), activities.end(), [](const auto &a, const auto &b) {
        if (get<0>(a) == get<0>(b)) {
            return get<1>(a) < get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    });

    int count = 0;
    int end_time = 0;
    int remain = k;

    while (remain > 0) {
        for (int i = 0; i < k; i++) {
            if (get<0>(activities[i]) >= end_time && get<2>(activities[i]) == false) {
                end_time = get<1>(activities[i]);
                get<2>(activities[i]) = true;
                remain--;
            }
        }
        end_time = 0;
        count++;
    }

    cout << count << endl;

    return 0;
}
