//计算二叉树含key的结点的层数
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

int getBiTreeNodeLayer(BiTree tree, int layer, char key) {
    if (tree == nullptr) return -1;
    if (tree->data == key) return layer;
    int temp = getBiTreeNodeLayer(tree->lChild, layer + 1, key);
    if (temp == -1) {
        temp = getBiTreeNodeLayer(tree->rChild, layer + 1, key);
    }
    return temp;
}

int getBiTreeNodeLayer(BiTree tree, char key) {
    int layer = getBiTreeNodeLayer(tree, 1, key);
    return layer;
}

int main() {
    BiTree tree;
    creatBiTree(tree);
    preOrderTranverse(tree);
    cout << endl;
    postOrderTranverse(tree);
    int layer = getBiTreeNodeLayer(tree, 'A');
    cout << endl << layer << endl;
    free(tree);
    system("pause");
    return 0;
}
