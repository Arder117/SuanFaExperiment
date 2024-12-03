// //
// // Created by ZhaoHao on 24-10-23.
// //
// #include<bits/stdc++.h>
// #define db double
// #define rep(x,y,z) for(int x=y;x<=z;++x)
// using namespace std;
// const int N = 1e6 + 10;
// const db qwq = 1e18;
// int n, s1, s2, t[N];
// db sur = 1e18;
//
// struct point {
//     db x, y;
// } d[N];
//
// db dis(int x, int y) {
//     db dx = d[x].x - d[y].x, dy = d[x].y - d[y].y;
//     return sqrt(dx * dx + dy * dy);
// }
//
// db run(int l, int r) {
//     if (l == r) return qwq;
//     int mid = (l + r) >> 1;
//     db d = min(run(l, mid), run(mid + 1, r));
//     int temp = 0;
//     rep(i, l, r)
//         if (dis(i, mid) < d) t[++temp] = i;
//     rep(i, 1, temp)
//         rep(j, i+1, temp) {
//             db dist = dis(t[i], t[j]);
//             d = min(d, dist);
//             if (dist < sur) {
//                 sur = dist;
//                 s1 = t[i];
//                 s2 = t[j];
//             }
//         }
//     return d;
// }
//
// int main() {
//     scanf("%d", &n);
//
//     rep(i, 1, n)
//         scanf("%lf%lf", &d[i].x, &d[i].y);
//     // sort(d+1,d+n+1,[&](point x,point y){return x.x<y.x;});
//     db ans = run(1, n);
//     if (d[s1].x + d[s1].y > d[s2].x + d[s2].y) swap(s1, s2);
//     printf("(%.2f,%.2f),(%.2f,%.2f),miniDist=%.3f", d[s1].x, d[s1].y, d[s2].x, d[s2].y, ans);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001

double min(double a, double b) { return a < b ? a : b; }

int n, temp[MAXN];

struct point {
    double x, y;

    friend bool operator <(point p1, point p2) {
        if (p1.x == p2.x) return p1.y < p2.y;
        return p1.x < p2.x;
    }
} p[MAXN];

bool cmp(int a, int b) {
    return p[a].y < p[b].y;
}

double getd(int x, int y) {
    return sqrt((p[x].x - p[y].x) * (p[x].x - p[y].x) + (p[x].y - p[y].y) * (p[x].y - p[y].y));
}

struct closest_pair {
    double dist;
    point p1, p2;
} cp;

closest_pair merge(int l, int r) {
    closest_pair res;
    res.dist = 2147483647.0;
    if (l == r) {
        res.p1 = p[l];
        res.p2 = p[l];
        return res;
    }
    if (l == r - 1) {
        res.dist = getd(l, r);
        if (p[l].x + p[l].y <= p[r].x + p[r].y) {
            res.p1 = p[l];
            res.p2 = p[r];
        } else {
            res.p1 = p[r];
            res.p2 = p[l];
        }
        return res;
    }
    int mid = (l + r) >> 1;
    closest_pair d1 = merge(l, mid);
    closest_pair d2 = merge(mid + 1, r);
    if (d1.dist < d2.dist) {
        res = d1;
    } else {
        res = d2;
    }
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
        if (fabs(p[mid].x - p[i].x) < res.dist) {
            temp[++cnt] = i;
        }
    }
    std::sort(temp + 1, temp + cnt + 1, cmp);
    for (int i = 1; i <= cnt; ++i) {
        for (int j = i + 1; j <= cnt && p[temp[j]].y - p[temp[i]].y < res.dist; ++j) {
            double d = getd(temp[i], temp[j]);
            if (d < res.dist) {
                res.dist = d;
                if (p[temp[i]].x + p[temp[i]].y <= p[temp[j]].x + p[temp[j]].y) {
                    res.p1 = p[temp[i]];
                    res.p2 = p[temp[j]];
                } else {
                    res.p1 = p[temp[j]];
                    res.p2 = p[temp[i]];
                }
            }
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    std::sort(p + 1, p + n + 1);
    cp = merge(1, n);
    printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf\n", cp.p1.x, cp.p1.y, cp.p2.x, cp.p2.y, cp.dist);
    return 0;
}
