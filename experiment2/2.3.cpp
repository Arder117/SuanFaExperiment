#include<bits/stdc++.h>
using namespace std;

#define Max 998244353

struct Matrix {
    unsigned long long M[2][2];
};

Matrix mul(Matrix a, Matrix b)
{
    Matrix c{};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.M[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c.M[i][j] = c.M[i][j] + a.M[i][k] * b.M[k][j];
                c.M[i][j] = c.M[i][j] % Max;
            }
        }
    }
    return c;
}

Matrix qul(unsigned long long t, Matrix a) {
    struct Matrix res;
    res.M[0][0] = 1;
    res.M[0][1] = 0;
    res.M[1][0] = 0;
    res.M[1][1] = 1;
    while (t > 0) {
        if (t % 2) res = mul(res, a);
        a = mul(a, a);
        t = t / 2;
    }
    return res;
}


int main() {
    unsigned long long n, sum = 0;
    scanf("%llu", &n);
    struct Matrix a;
    struct Matrix d;
    a.M[0][0] = 1;
    a.M[0][1] = 1;
    a.M[1][0] = 1;
    a.M[1][1] = 0;
    if (n == 1 || n == 2) printf("1");
    else {
        d = qul(n - 2, a);
        sum = (d.M[0][0] + d.M[0][1]) % Max;
        printf("%llu", sum);
    }
    return 0;
}
