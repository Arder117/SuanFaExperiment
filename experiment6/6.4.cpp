//
// Created by ZhaoHao on 24-12-4.
//

// 设有n个程序{1,2,…, n }要存放在长度为L的磁带上。程序i存放在磁带上的长度是 li，1≤i≤n。 程序存储问题要求确定这n 个程序在磁带上的一个存储方案，
// 使得能够在磁带上存储尽可能多的程序。 对于给定的n个程序存放在磁带上的长度，计算磁带上最多可以存储的程序数。
// 输入格式:第一行是2 个正整数，分别表示文件个数n和磁带的长度L。接下来的1行中，有n个正整数，表示程序存放在磁带上的长度。
// 输出格式:输出最多可以存储的程序数。
// 输入样例:在这里给出一组输入。例如：
// 6 50
// 2 3 13 8 80 20
// 输出样例:在这里给出相应的输出。例如：
// 5


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, L;
    cin >> n >> L;
    vector<int> lengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
    }

    sort(lengths.begin(), lengths.end());

    int count = 0;
    int remaining = L;
    for (int i = 0; i < n; ++i) {
        if (remaining >= lengths[i]) {
            remaining -= lengths[i];
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
