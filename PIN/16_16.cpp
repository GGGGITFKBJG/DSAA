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

LinkList mergeList(LinkList list1, LinkList list2) {
    if (list1 == nullptr || list2 == nullptr) return nullptr;
    LinkList list3 = new Node;
    list3->next = nullptr;
    
    PtrtoNode p3 = list3;
    while (list1->next != nullptr && list2->next != nullptr) {
        if (list1->next->data <= list2->next->data) {
            p3->next = list1->next;
            list1->next = list1->next->next;
        }
        else {
            p3->next = list2->next;
            list2->next = list2->next->next;
        }
        p3 = p3->next;
        p3->next = nullptr;
    }
    if (list1->next != nullptr) {
        p3->next = list1->next;
        list1->next = nullptr;
    }
    else if (list2->next != nullptr) {
        p3->next = list2->next;
        list2->next = nullptr;
    }
    return list3;
}

void reverseList(LinkList list) {
    if (list == nullptr && list->next == nullptr) return;
    PtrtoNode p = nullptr, c = list->next, n = nullptr;
    while (c != nullptr) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    list->next = p;
}

int main() {
    LinkList list1 = makeEmpty();
    for (int i = 1; i < 10; i++) {
        insert(list1, 14 - i);
    }
    printList(list1);
    reverseList(list1);
    printList(list1);
    deleteList(list1);
    
    getchar();
    return 0;
}