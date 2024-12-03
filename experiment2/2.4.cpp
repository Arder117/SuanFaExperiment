// //
// // Created by ZhaoHao on 24-10-23.
// //
//
// #include<stdio.h>
// #include <valarray>
//
// int x[1] = {1};
//
// int xx[3][3] = {
//     {1, 0, 1},
//     {0, 1, 0},
//     {1, 0, 1}
// };
//
// void getx(int maxnum, int num, int b[][maxnum]) {
//     if (num == 1) {
//         for (int i = 0; i < maxnum; i++) {
//             for (int j = 0; j < maxnum; j++) {
//                 b[i][j] = x[0];
//             }
//         }
//     } else if (num == 2) {
//         for (int i = 0; i < maxnum; i++) {
//             for (int j = 0; j < maxnum; j++) {
//                 b[i][j] = xx[i][j];
//             }
//         }
//     } else {
//         int c[][] = {{0}};
//         getx(maxnum, num - 1, c);
//         for (int i = 0; i < maxnum; i++) {
//             for (int j = 0; j < maxnum; j++) {
//                 b[i][j] = 0;
//                 for (int k = 0; k < maxnum; k++) {
//                     b[i][j] += c[i][k] * xx[k][j];
//                 }
//             }
//         }
//     }
// }
//
//
// void printx(int a[], int num) {
//     for (int i = 0; i < num; i++) {
//         // 计算最大值
//         int maxnum = pow(3, int(a[i] - 1));
//         // 初始化数组
//         int b[maxnum][maxnum] = {{0}};
//
//         getx(maxnum, a[i], b);
//
//         // 输出x
//         for (int j = 0; j < maxnum; j++) {
//             for (int k = 0; k < maxnum; k++) {
//                 if (b[j][k] == 1) {
//                     printf("x");
//                 } else {
//                     printf(" ");
//                 }
//             }
//             printf("\n");
//         }
//         printf("\n-\n");
//     }
// }
//
// int main() {
//     int a[100];
//     int num;
//     for (int i = 0; ; i++) {
//         scanf("%d", &a[i]);
//         if (a[i] == -1) {
//             num = i;
//             break;
//         }
//     }
//
//     printx(a, num);
//
//     return 0;
// }

#include<bits//stdc++.h>
using namespace std;

#define MAX 745

char a[MAX][MAX];

void Print(int n, int x, int y) {
    if (n == 1) a[x][y] = 'X';
    else {
        int m = (int) pow(3, n - 2);
        Print(n - 1, x, y);
        Print(n - 1, x, y + 2 * m);
        Print(n - 1, x + m, y + m);
        Print(n - 1, x + 2 * m, y);
        Print(n - 1, x + 2 * m, y + 2 * m);
    }
}


int main() {
    for (auto &i: a) {
        for (char &j: i) {
            j = ' ';
        }
    }
    Print(7, 0, 0);
    int num;
    cin >> num;
    while (num != -1) {
        int len = (int) pow(3, num - 1);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << '-' << endl;
        cin >> num;
    }
    system("pause");
    return 0;
}
