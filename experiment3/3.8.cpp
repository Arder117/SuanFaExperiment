//
// Created by ZhaoHao on 24-11-3.
//
#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int left, int right) {
    //（函数用于将数组a划分为两部分，使得左部分的所有元素都小于或等于某个特定的值p，而右部分的所有元素都大于p。p是从数组的left位置选择的元素。）
    int p = a[left];
    int i = left, j = right + 1;
    while (1) {
        do { i++; } while (a[i] < p && i <= right);
        do { j--; } while (a[j] > p);
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    swap(a[left], a[j]);
    return j;
}

int find(int a[], int left, int right, int k) {
    //找出第k小的数
    if (left == right) return a[left];
    int j = partition(a, left, right);
    int rank = j - left + 1;
    if (k == rank) return a[j];
    if (k < rank) //递归往左边搜
        return find(a, left, j - 1, k);
    //递归往右边搜
    return find(a, j + 1, right, k - rank);
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[10000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << find(a, 0, n - 1, k) << endl;
    return 0;
}
