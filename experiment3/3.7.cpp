//
// Created by ZhaoHao on 24-11-3.
//
#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    char data;
    node *lchild;
    node *rchild;
} bitnode, *bitree;

void creattree(bitree &T, char *hou, char *zhong, int len) {
    //后序中序建立二叉树
    if (len <= 0) {
        T = NULL;
        return;
    }
    T = static_cast<bitree>(malloc(sizeof(bitnode)));
    T->data = hou[len - 1];
    char p[2];
    p[0] = hou[len - 1];
    p[1] = '\0';
    char *p1 = strtok(zhong, p);
    char *p2 = strtok(NULL, p);
    int ln;
    if (p1 != NULL) ln = strlen(p1);
    else ln = 0;
    const auto q1 = static_cast<char *>(malloc(sizeof(char) * (ln + 1)));
    const auto q2 = static_cast<char *>(malloc(sizeof(char) * (len - ln)));
    int i;
    for (i = 0; i < ln; i++)
        q1[i] = hou[i];
    q1[i] = '\0';
    for (i = ln; i < len - 1; i++)
        q2[i - ln] = hou[i];
    q2[i - ln] = '\0';
    if (p1 == NULL) {
        T->lchild = NULL;
    }
    if (p2 == NULL) {
        T->rchild = NULL;
    }

    if (p1 != NULL) {
        creattree(T->lchild, q1, p1, ln);
        //creattree(T->rchild,p2,q2,len-ln-1);
    }
    if (p2 != NULL) {
        creattree(T->rchild, q2, p2, len - ln - 1);
    }
}

void pre(bitree T) {
    if (T == NULL)return;
    printf("%c", T->data);
    if (T->lchild)pre(T->lchild);
    if (T->rchild)pre(T->rchild);
}

int main() {
    char *hou, *zhong;
    int n;
    scanf("%d", &n);
    getchar();
    hou = (char *) malloc(sizeof(char) * (n + 1));
    zhong = (char *) malloc(sizeof(char) * (n + 1));
    scanf("%s", hou);
    scanf("%s", zhong);
    bitree T;
    creattree(T, hou, zhong, n);
    pre(T);

    system("pause");
}
