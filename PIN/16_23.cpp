//两个栈实现一个队列, C++风格实现
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 10

class Stack {
public:
    Stack() = default;
    ~Stack();

    bool initStack();
    void push(int data);
    void pop();
    int getTop();
    bool isEmpty();

private:
    int *base;
    int *top;
    int stackSize;
};

bool Stack::initStack() {
    base = new int[STACK_INIT_SIZE];
    if (base == nullptr) return false;
    top = base;
    stackSize = STACK_INIT_SIZE;
    return true;
}

Stack::~Stack() {
    if (base == nullptr) return;
    delete[] base;
}

void Stack::push(int data) {
    if (base == nullptr) return;
    if (top - base == stackSize) {
        int *temp = new int[stackSize + STACK_INCREMENT];
        memcpy(temp, base, sizeof(int) * stackSize);
        delete[] base;
        base = temp;
        top = base + stackSize;
        stackSize += STACK_INCREMENT;
    }
    *top = data;
    top++;
}

void Stack::pop() {
    if (base == nullptr || base == top) return;
    top--;
}

int Stack::getTop() {
    if (base == nullptr || base == top) return -1;
    return *(top - 1);
}

bool Stack::isEmpty() {
    if (base == nullptr) return true;
    return base == top;
}

class Queue {
public:
    Queue() = default;
    ~Queue();

    bool initQueue();
    bool enQueue(int data);
    bool deQueue(int &x);
    bool isEmpty();
private:
    Stack *s1;
    Stack *s2;
};

bool Queue::initQueue() {
    s1 = new Stack;
    s1->initStack();
    if (s1 == nullptr) return false;
    s2 = new Stack;
    s2->initStack();
    if (s2 == nullptr) {
        delete s1;
        return false;
    }
    return true;
}

Queue::~Queue() {
    if (s1 != nullptr) delete s1;
    if (s2 != nullptr) delete s2;
}

bool Queue::enQueue(int data) {
    if (s1 == nullptr || s2 == nullptr) return false;
    s1->push(data);
    return true;
}

bool Queue::deQueue(int &x) {
    if (s1 == nullptr || s2 == nullptr) return false;
    if (this->isEmpty()) return false;
    if (s2->isEmpty()) {
        while (!s1->isEmpty()) {
            s2->push(s1->getTop());
            s1->pop();
        }
    }
    x = s2->getTop();
    s2->pop();
    return true;
}

bool Queue::isEmpty() {
    if (s1 == nullptr || s2 == nullptr) return true;
    return s1->isEmpty() && s2->isEmpty();
}

int main() {
    Queue q;
    q.initQueue();
    for (int i = 0; i < 11; i++) {
        q.enQueue(i);
    }
    int x;
    while (!q.isEmpty()) {
        q.deQueue(x);
        cout << x << " ";
    }
    cout << endl;

    q.enQueue(10014);
    q.deQueue(x);
    cout << x << endl;

    system("pause");
    return 0;
}
