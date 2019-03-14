//判断链表是否有环
#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
} *LinkList, *LoopLinkList, *PtrtoNode;

LinkList makeEmpty() {
    LinkList list = new Node;
    list->next = nullptr;
    return list;
}

LinkList makeList() {
    LinkList list = new Node;
    list->next = nullptr;
    PtrtoNode p1, p2 = list;
    int data;
    while (cin >> data) {
        p1 = new Node;
        p1->data = data;
        p1->next = nullptr;
        p2->next = p1;
        p2 = p2->next;
    }
    return list;
}

LoopLinkList makeLoopList() {
    PtrtoNode list = new Node;
    list->next = list;
    PtrtoNode p1, p2 = list;
    int data;
    while (cin >> data) {
        p1 = new Node;
        p1->next = list;
        p2->next = p1;
        p2 = p2->next;
    }
    return list;
}

void deleteLinkList(LinkList list) {
    if (list == nullptr) return;
    PtrtoNode p1 = list, p2;
    while (p1 != nullptr) {
        p2 = p1->next;
        delete p1;
        p1 = p2;
    }
}

void deleteLoopList(LoopLinkList list) {
    if (list == nullptr) return;
    PtrtoNode p1 = list, p2;
    do {
        p2 = p1->next;
        delete p1;
        p1 = p2;
    } while (p1 != list);
}

void printList(LinkList list) {
    if (list == nullptr) return;
    PtrtoNode p = list->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool isLoopLinkList(LinkList list) {
    if (list == nullptr) return false;
    PtrtoNode slow = list, fast = list->next;
    while (fast != nullptr && fast->next != nullptr && slow != fast) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == nullptr || fast->next == nullptr) return false;
    else return true;
}

int main() {
    LinkList list = makeList();//生成直链表
    printList(list);

    PtrtoNode p = list;
    while (p->next != nullptr) p = p->next;//p指向最后一个节点
    p->next = list->next->next;//制做环，尾结点指向第2个元素，要保证list至少有2个元素

    bool flag = isLoopLinkList(list);
    cout << "isLoopLinkList? " << flag << endl;

    p->next = nullptr;//恢复成直链表，便于销毁

    deleteLinkList(list);
    getchar();
    return 0;
}