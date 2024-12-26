//
// Created by ZhaoHao on 24-12-13.
//

// 设集合S={x1,x2,…,xn}是一个正整数集合，c是一个正整数，子集和问题判定是否存在S的一个子集S1，使S1中的元素之和为c。试设计一个解子集和问题的回溯法
// 并输出利用回溯法在搜索树（按输入顺序建立）中找到的第一个解。
// 输出利用回溯法找到的第一个解，以空格分隔，最后一个输出的后面有空格。当问题无解时，输出“No Solution!”。


#include <iostream>
using namespace std;

int numElements;
int targetSum;
int currentSum = 0;
int totalSum = 0;
int elements[10000];
bool selected[10000];

bool Backtrack(int index) {
    if (currentSum == targetSum) return true;
    if (index >= numElements) return false;

    totalSum -= elements[index];

    if (currentSum + elements[index] <= targetSum) {
        selected[index] = true;
        currentSum += elements[index];
        if (Backtrack(index + 1)) return true;
        currentSum -= elements[index];
    }

    if (currentSum + totalSum >= targetSum) {
        selected[index] = false;
        if (Backtrack(index + 1)) return true;
    }

    totalSum += elements[index];
    return false;
}

int main() {
    cin >> numElements >> targetSum;
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
        totalSum += elements[i];
    }
    if (!Backtrack(0))
        cout << "No Solution!" << endl;
    else {
        for (int i = 0; i < numElements; i++) {
            if (selected[i]) cout << elements[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
