#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
} *LinkList, *PtrtoNode;

LinkList makeEmpty() {
    LinkList list = new Node;
    list->next = nullptr;
    return list;
}

void insert(PtrtoNode p, int elem) {
    if (p == nullptr) return;
    PtrtoNode temp = new Node;
    temp->data = elem;
    temp->next = p->next;
    p->next = temp;
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

PtrtoNode findPrevious(LinkList list, PtrtoNode p) {
    if (list == nullptr || p == nullptr) return nullptr;
    PtrtoNode temp = list;
    while (temp != nullptr) {
        if (temp->next == p) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void deleteNode(LinkList list, PtrtoNode p) {
    if (list == nullptr || p == nullptr) return;
    PtrtoNode prev = findPrevious(list, p);
    if (prev == nullptr) return;
    prev->next = p->next;
    delete p;
}

void deleteList(LinkList list) {
    PtrtoNode temp;
    while (list != nullptr) {
        temp = list->next;
        delete list;
        list = temp;
    }
}
int main() {
    LinkList list = makeEmpty();
    for(int i = 0; i < 5; i++ ) insert(list, i);
    printList(list);
    deleteNode(list, list->next);
    printList(list);
    insert(list, 11);
    printList(list);
    deleteList(list);

    getchar();
    return 0;
}