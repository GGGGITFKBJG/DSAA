#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
} *LoopLinkList, *PtrtoNode;

LoopLinkList makeEmpty() {
    PtrtoNode list = new Node;
    list->next = list;
    return list;
}

PtrtoNode insertNode(LoopLinkList list, PtrtoNode pos, int elem) {
    if (list == nullptr || pos == nullptr) return nullptr;
    PtrtoNode p = new Node;
    p->data = elem;
    p->next = pos->next;
    pos->next = p; 
    return p;
}

void printList(LoopLinkList list) {
    if (list == nullptr) return;
    PtrtoNode p = list->next;
    while (p != list) {
        cout << p->data << " ";
        p = p->next;
    }
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

int main() {
    LoopLinkList list = makeEmpty();
    for (int i = 0; i < 15; i++) {
        insertNode(list, list, i);
    }
    printList(list);

    deleteList(list);
    getchar();
    return 0;
}