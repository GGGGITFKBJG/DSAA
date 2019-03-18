//计算二叉树的叶子结点数
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

int getLeavesCount(BiTree tree) {
    if (tree == nullptr) return 0;
    if (tree->lChild == nullptr && tree->rChild == nullptr) return 1;//终止条件
    int lc = 0;
    lc += getLeavesCount(tree->lChild);
    lc += getLeavesCount(tree->rChild);
    return lc;
}

int main() {
    BiTree tree;
    creatBiTree(tree);
    preOrderTranverse(tree);
    cout << endl;
    postOrderTranverse(tree);
    int lc = getLeavesCount(tree);
    cout << endl << lc << endl;
    free(tree);
    system("pause");
    return 0;
}
