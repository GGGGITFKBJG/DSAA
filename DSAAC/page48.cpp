//栈的数组实现
typedef int ElementType;
class StackRecord {
public:
    StackRecord() = default;

    int capacity;
    int topOfStack;
    ElementType *array;
};
typedef StackRecord* Stack;

#define EmptyTOS (-1)
#define MinStackSize (5)

void MakeEmpty(Stack s) {
    s->topOfStack = EmptyTOS;
}
int IsEmpty(Stack s) {
    return s->topOfStack == EmptyTOS;
}
int IsFull(Stack s) {
    return s->topOfStack == s->capacity - 1;
}
Stack CreatStack(int maxElement) {
    if (maxElement < MinStackSize) return nullptr;
    Stack s = new StackRecord;
    if (s == nullptr) return nullptr;
    s->array = new int[maxElement];
    if (s->array == nullptr) {
        delete s;
        return nullptr;
    }
    s->capacity = maxElement;
    MakeEmpty(s);
    return s;
}
void DisposeStack(Stack s) {
    if (s != nullptr) {
        delete [] s->array;
        delete s;
    }
}

void Push(ElementType x, Stack s) {
    if (IsFull(s)) return;
    s->array[++s->topOfStack] = x;//->优先级大于前置++
}
ElementType Top(Stack s) {
    return s->array[s->topOfStack];
}
void Pop(Stack s) {
    if (IsEmpty(s)) return;
    s->topOfStack--;
}
ElementType TopAndPop(Stack s) {
    if (IsEmpty(s)) return 0;
    return s->array[s->topOfStack--];
}

#include <iostream>
using namespace std;

int main()
{
    Stack s = CreatStack(8);
    cout << "capacity: " << s->capacity << endl;
    cout << "isEmpty? " << IsEmpty(s) << endl;
    cout << "isFull? " << IsFull(s) << endl;
    for (int i = 0; i < 8; i++) {
        Push(i + 1, s);
    }
    cout << "TopAndPop" << TopAndPop(s) << endl;
    cout << "capacity: " << s->capacity << "topOfStack: " << s->topOfStack << endl;
    DisposeStack(s);
    getchar();
    return 0;
}