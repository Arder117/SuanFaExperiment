//
// Created by ZhaoHao on 24-11-3.
//

//给定一个全由小写字母构成的字符串，求它的全排列，按照字典序从小到大输出。
//输入格式: 一行，一个字符串，长度不大于8。
//输出格式: 输出所有全排列，每行一种排列形式，字典序从小到大。
//输入样例: abc
//输出样例: abc acb bac bca cab cba

#include <bits/stdc++.h>
using namespace std;

void sort(char a[], int left, int right) {
    int i, j, t;
    char temp;
    if (left > right) {
        return;
    }
    temp = a[left];
    i = left;
    j = right;
    while (i != j) {
        while (a[j] >= temp && i < j)
            j--;
        while (a[i] <= temp && i < j)
            i++;
        if (i < j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = temp;
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}


int main() {
    char s[10];
    cin >> s;
    sort(s, 0, strlen(s) - 1);
    do {
        cout << s << endl;
    } while (next_permutation(s, s + strlen(s)));

    system("pause");
}
