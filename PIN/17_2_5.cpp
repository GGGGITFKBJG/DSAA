//给定先序, 中序序列, 求后序序列和按层次序列
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

typedef char ElementType;

typedef struct BiTNode {
    ElementType data;
    BiTNode *lChild;
    BiTNode *rChild;
} *BiTree, *PtrtoBiTree;

BiTree creatTreeBySeq(const char *pre, const char *in, int n) {//<--
    if (pre == nullptr || in == nullptr) return nullptr;
    if (n == 0) return nullptr;//叶子处的终止条件
    PtrtoBiTree temp = new BiTNode;
    if (temp == nullptr) return nullptr;
    temp->data = pre[0];//先序序列中第一个为根节点
    int i;
    for (i = 0; i < n; i++) {//在中序序列中找根节点
        if (in[i] == pre[0]) break;
    }
    temp->lChild = creatTreeBySeq(pre + 1, in, i);//左子树
    temp->rChild = creatTreeBySeq(pre + i + 1, in + i + 1, n - i - 1);//右子树
    return temp;
}

void preOrderTranverse(BiTree tree) {
    if (tree == nullptr) return;
    cout << tree->data;
    preOrderTranverse(tree->lChild);
    preOrderTranverse(tree->rChild);
}

void inOrderTranverse(BiTree tree) {
    if (tree == nullptr) return;
    inOrderTranverse(tree->lChild);
    cout << tree->data;
    inOrderTranverse(tree->rChild);
}

void postOrderTranverse(BiTree tree) {
    if (tree == nullptr) return;
    postOrderTranverse(tree->lChild);
    postOrderTranverse(tree->rChild);
    cout << tree->data;
}

void layerOrderTranverse(BiTree tree) {
    if (tree == nullptr) return;
    queue<PtrtoBiTree> q;
    q.push(tree);
    PtrtoBiTree temp;
    while (!q.empty()) {
        temp = q.front();
        cout << temp->data;
        q.pop();
        if (temp->lChild != nullptr) q.push(temp->lChild);
        if (temp->rChild != nullptr) q.push(temp->rChild);
    }
}

void freeBiTree(BiTree tree) {
    if (tree == nullptr) return;
    freeBiTree(tree->lChild);
    freeBiTree(tree->rChild);
    delete tree;
}

int main() {
    const char *pre = "ABCDEFG";
    const char *in = "CDBEAGF";
    /*
            A
           / \
          B   F
         / \ / 
        C  E G 
         \
          D
    */
    BiTree tree = creatTreeBySeq(pre, in, 7);
    cout << "preOrderTranverse: ";
    preOrderTranverse(tree);
    cout << endl;
    cout << "inOrderTranverse: ";
    inOrderTranverse(tree);
    cout << endl;
    cout << "postOrderTranverse: ";
    postOrderTranverse(tree);
    cout << endl;
    cout << "layerOrderTranverse: ";
    layerOrderTranverse(tree);
    cout << endl;
    freeBiTree(tree);
    
    system("pause");
    return 0;
}
