//约瑟夫环问题
//单链表实现
#include <iostream>
using namespace std;

typedef struct Node {
    int id;
    int key;
    Node *next;
} *LoopLinkList, *PtrtoNode;

PtrtoNode makeList() {
    int i = 1, key;
    PtrtoNode list = new Node;//头结点
    list->next = list;

    PtrtoNode p1, p2 = list;
    while (cin >> key) {
        p1 = new Node;
        p1->id = i++;
        p1->key = key;
        p1->next = list;

        p2->next = p1;
        p2 = p2->next;
    }
    return list;
}

PtrtoNode findPrevious(LoopLinkList list, PtrtoNode p) {
    if (list == nullptr || p == nullptr) return nullptr;
    PtrtoNode temp = list;
    while (temp->next != list && temp->next != p) {
        temp = temp->next;
    }
    if (temp->next == list) return nullptr;
    return temp;
}

void deleteNode(LoopLinkList list, PtrtoNode p) {
    if (list == nullptr || p == nullptr) return;
    PtrtoNode temp = findPrevious(list, p);
    temp->next = p->next;
    delete p;
}

void deleteList(LoopLinkList list) {
    if (list == nullptr) return;
    PtrtoNode p1 = list, p2;
    do {
        p2 = p1->next;
        delete p1;
        p1 = p2;
    } while (p1 != list);
}

void printList(LoopLinkList list) {
    if (list == nullptr) return;
    PtrtoNode p = list->next;
    while (p != list) {
        cout << p->id << ", " << p->key << endl;
        p = p->next;
    }
}

void JosephSolve(LoopLinkList list) {
    if (list == nullptr || list->next == list) return;
    PtrtoNode p = list->next, temp;
    int i = p->key;
    while (list->next != list) {
        while (--i) {
            p = p->next;
            if (p == list) p = p->next;
        }
        cout << "id: " << p->id << " ";
        temp = p->next;
        if (temp == list) temp = temp->next;
        i = p->key;
        deleteNode(list, p);
        p = temp;
    }
    cout << endl;
}

int main() {
    LoopLinkList list = makeList();
    cout << "initial list: " << endl;
    printList(list);
    cout << "solution: " << endl;
    JosephSolve(list);
    cout << "after: " << endl;
    printList(list);
    deleteList(list);

    getchar();
    return 0;
}