#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
} *PtrtoNode, *LinkList;

LinkList makeEmpty() {
    LinkList list = new Node;
    list->next = nullptr;
    return list;
}

PtrtoNode insert(PtrtoNode p, int elem) {
    if (p == nullptr) return nullptr;
    PtrtoNode temp = new Node;
    if (temp == nullptr) return nullptr;
    temp->data = elem;
    temp->next = p->next;
    p->next = temp;
    return temp;
}

PtrtoNode findPrevious(LinkList list, PtrtoNode p) {
    if (list == nullptr || p == nullptr) return nullptr;
    PtrtoNode temp = list;
    while (temp != nullptr && temp->next != p) temp = temp->next;
    return temp;
}

void deleteNode(LinkList list, PtrtoNode p) {
    if (list == nullptr || p == nullptr) return;
    PtrtoNode pre = findPrevious(list, p);
    if (pre != nullptr) {
        pre->next = p->next;
        delete p;
    }
}

void deleteList(LinkList list) {
    if (list == nullptr) return;
    PtrtoNode temp = list;
    while (list != nullptr) {
        temp = temp->next;
        delete list;
        list = temp;
    }
}

void printList(LinkList list) {
    if (list == nullptr) return;
    PtrtoNode temp = list->next;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

PtrtoNode insertInOrder(LinkList list, int elem) {
    if (list == nullptr) return nullptr;
    PtrtoNode p = new Node;
    p->data = elem;
    PtrtoNode temp = list;
    while (temp->next != nullptr && elem > temp->next->data) {
        temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
    return p;
}

int main() {
    LinkList list = makeEmpty();
    for (int i = 0; i < 15; i++) {
        insert(list, 15 - i);
    }
    printList(list);

    insertInOrder(list, 0);
    printList(list);
    insertInOrder(list, 5);
    printList(list);
    insertInOrder(list, 20);
    printList(list);
    
    getchar();
    return 0;
}