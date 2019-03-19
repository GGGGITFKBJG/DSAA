//二叉排序树最低公共祖先问题
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

PtrtoBiTNode findLowestCommonAncestor(BiTree tree, char a, char b) {
    if (tree == nullptr) return nullptr;
    if (tree->data == a || tree->data == b) return nullptr;
    PtrtoBiTNode temp = tree;//当前结点
    while (temp != nullptr) {
        if (temp->data > a && temp->data > b && 
            temp->lChild->data != a && temp->lChild->data != b) {//a, b都在左子树
            temp = temp->lChild;
        }
        else if (temp->data < a && temp->data < b &&
            temp->rChild->data != a && temp->rChild->data != b) {//a, b都在右子树
            temp = temp->rChild;
        }
        else {//(a, b在左右子树)或(a或b为当前结点的子结点)
            return temp;
        }
    }
    return nullptr;//没找到
}

int main() {
    BiTree tree;
    creatBiTree(tree);//用户要保证输入的是排序树
    preOrderTranverse(tree);
    cout << endl;
    postOrderTranverse(tree);
    cout << endl;
    char a, b;
    cin >> a >> b;
    PtrtoBiTNode result = findLowestCommonAncestor(tree, a, b);
    if(result != nullptr) cout << result->data << endl;
    free(tree);
    system("pause");
    return 0;
}
