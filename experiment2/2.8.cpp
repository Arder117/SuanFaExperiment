#include<bits/stdc++.h>
using namespace std;

#define Max 10000

int compare(const void *e1, const void *e2) {
    return *(int *) e1 - *(int *) e2;
}

int main() {
    int n = 0;
    cin >> n;
    int x[Max] = {}, y[Max] = {};
    int i = 0;
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    qsort(y, n, sizeof(y[0]), compare); //快速排序
    int Mid = y[n / 2];
    long sum = 0;
    for (i = 0; i < n; i++) {
        sum += abs(y[i] - Mid);
    }
    cout << sum;
    return 0;
}
