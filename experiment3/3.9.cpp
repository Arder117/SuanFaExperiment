//
// Created by ZhaoHao on 24-11-3.
//
#include<bits/stdc++.h>
using namespace std;

int n, a[10010], temp[10010], num;

void Merge(int a[], int b[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while ((i <= m) && (j <= r))
        if (a[i] <= a[j]) b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            num += m - i + 1;
        }
    if (i > m)
        for (int q = j; q <= r; q++) b[k++] = a[q];
    else
        for (int q = i; q <= m; q++) b[k++] = a[q];
    for (int p = l; p <= r; p++)
        a[p] = temp[p];
}

void MergeSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    } else {
        int i = (left + right) / 2;
        MergeSort(a, left, i);
        MergeSort(a, i + 1, right);
        Merge(a, temp, left, i, right);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    num = 0;
    MergeSort(a, 0, n - 1);

    cout << num << endl;

    system("pause");
}
