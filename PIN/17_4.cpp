//计算二叉树的深度(高度)
#include <iostream>
#include <cstdlib>
using namespace std;

typedef char ElementType;

typedef struct BiTNode {
    ElementType data;
    BiTNode *lChild;
    BiTNode *rChild;
} *BiTree, *PtrtoBiTNode;

void creatBiTree(BiTree& tree) {
    char c;
    cin >> c;
    if (c == '#') tree = nullptr;
    else {
        tree = new BiTNode;
        if (tree == nullptr) return;
        tree->data = c;
        creatBiTree(tree->lChild);
        creatBiTree(tree->rChild);
    }
}

void freeBiTree(BiTree& tree) {
    if (tree == nullptr) return;
    free(tree->lChild);
    free(tree->rChild);
    delete tree;
}

void preOrderTranverse(BiTree tree) {
    if (tree == nullptr) return;
    cout << tree->data;
    preOrderTranverse(tree->lChild);
    preOrderTranverse(tree->rChild);
}

void postOrderTranverse(BiTree tree) {
    if (tree == nullptr) return;
    postOrderTranverse(tree->lChild);
    postOrderTranverse(tree->rChild);
    cout << tree->data;
}

int getDepth(BiTree tree) {
    if (tree == nullptr) return 0;//终止条件
    int d = 1, e = 1;//根结点深度为1
    d += getDepth(tree->lChild);
    e += getDepth(tree->rChild);
    return d > e ? d : e;
}

int main() {
    BiTree tree;
    creatBiTree(tree);
    preOrderTranverse(tree);
    cout << endl;
    postOrderTranverse(tree);
    int d = getDepth(tree);
    cout << endl << d << endl;
    free(tree);
    system("pause");
    return 0;
}
