//
// Created by ZhaoHao on 24-12-4.
//
// 月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，
// 请你计算可以获得的最大收益是多少。注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，
// 总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，
// 获得 72 + 45/2 = 94.5（亿元）。
// 输入格式：
// 每个输入包含一个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 D 表示市场最大需求量。
// 随后一行给出 N 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
// 输出格式：对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。
// 输入样例：
// 3 20
// 18 15 10
// 75 72 45
// 输出样例：
// 94.50


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<double> stock(n), total_price(n);
    for (int i = 0; i < n; i++) {
        cin >> stock[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> total_price[i];
    }

    vector<tuple<double, double, double> > profit(n);
    for (int i = 0; i < n; i++) {
        profit[i] = tuple(stock[i], total_price[i], static_cast<double>(total_price[i]) / stock[i]);
    }

    sort(profit.begin(), profit.end(), [](const auto &a, const auto &b) {
        return get<2>(a) > get<2>(b);
    });

    double max_profit = 0.0;
    for (const auto &[stock, total_price, price]: profit) {
        if (stock < d) {
            max_profit += total_price;
            d -= stock;
        } else {
            max_profit += price * d;
            break;
        }
    }

    printf("%.2f\n", max_profit);

    return 0;
}
