//栈实现括号匹配
#include <iostream>
#include <cstring>
#include <cstdlib>
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

bool isOpenChar(char c) {
    if (c == '(' || c == '[' || c == '{') return true;
    return false;
}

bool isCloseChar(char c) {
    if (c == ')' || c == ']' || c == '}') return true;
    return false;
}

bool match(char c1, char c2) {
    if (c1 == '(' && c2 == ')') return true;
    if (c1 == '[' && c2 == ']') return true;
    if (c1 == '{' && c2 == '}') return true;
    return false;
}

bool bracketCheck() {
    char c;
    Stack *s = initStack();
    if (s == nullptr) return false;
    while (cin >> c) {
        if (isOpenChar(c)) push(s, c);//char 存成 int
        else if (isCloseChar(c)) {
            if (isEmpty(s) || !match(top(s), c)) {
                deleteStack(s);
                return false;
            }
            else pop(s);
        }
    }
    bool flag;
    if (isEmpty(s)) flag = true;
    else flag = false;
    deleteStack(s);
    return flag;
}

int main() {
    cout << "match? " << bracketCheck() << endl;

    system("pause");
    return 0;
}
