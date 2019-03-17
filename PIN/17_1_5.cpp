//二叉树的按层次遍历使用STL queue
#include <iostream>
#include <cstdlib>
#include <queue>//按层次遍历需要用
using namespace std;

typedef struct BiTNode {//二叉树结点
    BiTNode *lChild;
    BiTNode *rChild;
    char data;
} *BiTree, *PtrtoBiTNode;

void creatBiTree(BiTree& tree) {//先序创建, 可能对变量tree作修改, 所以传入引用
    char c;
    cin >> c;
    if (c == '#') tree = nullptr;//终止条件, 修改变量tree
    else {
        tree = new BiTNode;//修改变量tree
        tree->data = c;
        creatBiTree(tree->lChild);
        creatBiTree(tree->rChild);
    }
}

void freeBiTree(BiTree& tree) {//后序销毁
    if (tree == nullptr) return;//终止条件
    freeBiTree(tree->lChild);
    freeBiTree(tree->rChild);
    delete tree;
    tree = nullptr;//根结点置NULL
}

void preOrderTraverse(BiTree tree) {//先序遍历
    if (tree == nullptr) return;
    cout << tree->data;
    preOrderTraverse(tree->lChild);
    preOrderTraverse(tree->rChild);
}

void inOrderTraverse(BiTree tree) {//中序遍历
    if (tree == nullptr) return;
    inOrderTraverse(tree->lChild);
    cout << tree->data;
    inOrderTraverse(tree->rChild);
}

void postOrderTraverse(BiTree tree) {//后序遍历
    if (tree == nullptr) return;
    postOrderTraverse(tree->lChild);
    postOrderTraverse(tree->rChild);
    cout << tree->data;
}

void layerOrderTraverse(BiTree tree) {//按层次遍历
    if (tree == nullptr) return;
    queue<PtrtoBiTNode> q;//-----------------------------------
    q.push(tree);
    PtrtoBiTNode ptr;
    while (!q.empty()) {
        ptr = q.front();
        q.pop();
        cout << ptr->data;
        if(ptr->lChild != nullptr) q.push(ptr->lChild);
        if (ptr->rChild != nullptr) q.push(ptr->rChild);
    }
}

int main() {
    BiTree tree;
    creatBiTree(tree);//ABC##D##E#F##
    /*
                A
               / \
              B   E
             / \   \
            C   D   F
    */
    preOrderTraverse(tree);//ABCDEF
    cout << endl;
    inOrderTraverse(tree);//CBDAEF
    cout << endl;
    postOrderTraverse(tree);//CDBFEA
    cout << endl;
    layerOrderTraverse(tree);//ABECDF
    cout << endl;

    freeBiTree(tree);
    system("pause");
    return 0;
}