//栈的链表实现
typedef int ElementType;

class Node {
public:
    Node() = default;
    Node(ElementType ele) : element(ele) {};
    ElementType element;
    Node* next;
};

typedef Node* Stack;

int IsEmpty(Stack s) {
    return s->next == nullptr;
}

void Push(ElementType x, Stack s) {
    Node* temp = new Node(x);
    temp->next = s->next;
    s->next = temp;
}

void Pop(Stack s) {
    if (!IsEmpty(s)) {
        Node* temp = s->next;
        s->next = temp->next;
        delete temp;
    }
}

void MakeEmpty(Stack s) {
    if (s != nullptr) {
        while (!IsEmpty(s)) Pop(s);
    }
}
Stack CreateStack() {
    Stack s = new Node;
    s->next = nullptr;
    MakeEmpty(s);
    return s;
}

ElementType Top(Stack s) {
    return s->next->element;
}

void DisposeStack(Stack s) {//销毁栈
    Node* temp1 = s;
    Node* temp2;
    while (temp1 != nullptr) {
        temp2 = temp1->next;
        delete temp1;
        temp1 = temp2;
    }
}

#include <iostream>
using namespace std;

int main()
{
    Stack s = CreateStack();
    Push(34, s);
    for (int i = 0; i < 5; i++) {
        Push(i, s);
    }
    Pop(s);
    for (int i = 0; i < 3; i++) {
        cout << Top(s) << endl;
        Pop(s);
    }
    cout << "end" << endl;
    cout << Top(s) << endl;
    Pop(s);
    Pop(s);
    cout << "isempty = " << IsEmpty(s) << endl;
    DisposeStack(s);

    getchar();
    return 0;
}