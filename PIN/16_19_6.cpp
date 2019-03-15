//栈的数组实现

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 10

#include <iostream>
#include <cstring>
using namespace std;

struct Stack {
    int *base;
    int *top;
    int stackSize;
};

Stack* initStack() {
    Stack *s = new Stack;
    s->base = new int[STACK_INIT_SIZE];
    if (s->base == nullptr) return nullptr;
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
    return s;
}

void deleteStack(Stack *s) {
    if (s == nullptr) return;
    delete[] s->base;
    delete s;
}

void push(Stack *s, int data) {
    if (s == nullptr) return;
    if (s->top - s->base == s->stackSize) {
        int *temp = new int[s->stackSize + STACK_INCREMENT];
        if (temp == nullptr) return;
        memcpy(temp, s->base, sizeof(int) * s->stackSize);
        delete s->base;
        s->base = temp;
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACK_INCREMENT;
    }
    *(s->top) = data;
    s->top++;
}

void pop(Stack *s) {
    if (s == nullptr) return;
    if (s->top == s->base) return;
    s->top--;
}

int top(Stack *s) {
    if (s == nullptr || s->base == s->top) return -1;
    return *(s->top - 1);
}

bool isEmpty(Stack *s) {
    if (s == nullptr) return true;
    return s->base == s->top;
}

int main() {
    Stack *s = initStack();
    for (int i = 0; i < 11; i++) {
        push(s, i);
        cout << top(s) << " ";
    }
    cout << endl;
    pop(s);
    cout << top(s) << " " << endl;
    while (!isEmpty(s)) {
        cout << top(s) << " ";
        pop(s);
    }
    cout << endl;
    deleteStack(s);
    getchar();
    return 0;
}
