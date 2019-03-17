//二叉树的创建, 遍历与销毁
#include <iostream>
#include <cstdlib>
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

typedef struct LiNode {//链表结点
    PtrtoBiTNode data;//二叉树指针类型
    LiNode *next;
} *LinkList, *PtrtoLiNode;

class Queue {//队列
public:
    Queue() {
        front = nullptr;
    }
    ~Queue() {
        while (!isEmpty()) deQueue();
    }
    bool enQueue(PtrtoBiTNode p) {
        PtrtoLiNode temp = new LiNode;
        if (temp == nullptr) return false;
        temp->data = p;
        temp->next = nullptr;
        if (front == nullptr) {
            front = temp;
            rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
        return true;
    }
    bool deQueue() {
        if (front == nullptr) return false;
        PtrtoLiNode temp = front;
        front = front->next;
        delete temp;
        return true;
    }
    bool deQueue(PtrtoBiTNode& p) {
        if (front == nullptr) return false;
        PtrtoLiNode temp = front;
        front = front->next;
        p = temp->data;
        delete temp;
        return true;
    }
    bool isEmpty() {
        return front == nullptr;
    }
private:
    PtrtoLiNode front, rear;
};

void layerOrderTraverse(BiTree tree) {//按层次遍历
    if (tree == nullptr) return;
    Queue q;
    q.enQueue(tree);
    PtrtoBiTNode ptr;
    while (!q.isEmpty()) {
        q.deQueue(ptr);
        cout << ptr->data;
        if(ptr->lChild != nullptr) q.enQueue(ptr->lChild);
        if (ptr->rChild != nullptr) q.enQueue(ptr->rChild);
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
