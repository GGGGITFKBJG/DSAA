//栈实现二-八进制转换
#include <iostream>
#include <cstring>
using namespace std;

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 10

struct Stack {
    int *base;
    int *top;
    int stackSize;
};

Stack* initStack() {
    Stack* s = new Stack;
    if (s == nullptr) return nullptr;
    s->base = new int[STACK_INIT_SIZE];
    if (s->base == nullptr) {
        delete s;
        return nullptr;
    }

    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
    return s;
}

void push(Stack *s, int data) {
    if (s == nullptr) return;
    if (s->top - s->base == s->stackSize) {
        int *temp = new int[s->stackSize + STACK_INIT_SIZE];
        memcpy(temp, s->base, sizeof(int) * s->stackSize);
        delete[] s->base;
        s->base = temp;
        s->top = s->base + s->stackSize;
        s->stackSize += STACK_INCREMENT;
    }
    *(s->top) = data;
    s->top++;
}

void pop(Stack *s) {
    if (s == nullptr) return;
    if (s->base == s->top) return;
    s->top--;
}

int top(Stack *s) {
    if (s == nullptr) return -1;
    if (s->base == s->top) return -1;
    return *(s->top - 1);
}

bool isEmpty(Stack *s) {
    if (s == nullptr) return true;
    return s->base == s->top;
}

void deleteStack(Stack *s) {
    if (s == nullptr) return;
    delete[] s->base;
    delete s;
}

void b2o() {
    Stack *s1 = initStack();
    Stack *s2 = initStack();
    if (s1 == nullptr && s2 != nullptr) {//确保正常释放
        deleteStack(s2);
        return;
    }
    else if (s1 != nullptr && s2 == nullptr) {
        deleteStack(s1);
        return;
    }
    else if (s1 == nullptr && s2 == nullptr) return;

    char c;
    while (cin >> c) {
        if (c == '0' || c == '1') push(s1, c - 48);
    }
    int sum = 0;
    while (!isEmpty(s1)) {
        for (int i = 0; i < 3 && !isEmpty(s1); i++) {
            sum += top(s1) << i;//sum += top(s1) * pow(2, i);
            pop(s1);
        }
        push(s2, sum);
        sum = 0;
    }
    while (!isEmpty(s2)) {
        cout << top(s2);
        pop(s2);
    }
    cout << endl;
    deleteStack(s1);
    deleteStack(s2);
}

int main() {
    b2o();
    getchar();
    return 0;
}
