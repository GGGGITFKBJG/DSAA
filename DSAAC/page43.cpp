//链表的数组实现
#define SpaceSize 20
#include <iostream>
using namespace std;

typedef int List;
typedef int Position;
typedef int ElementType;

class Node {
public:
    ElementType element;
    int next;
};

class Node CursorSpace[SpaceSize];

void InitializeCursorSpace() {
    int i = 0;
    while (i < SpaceSize - 1) {
        CursorSpace[i].next = i + 1;
        i++;
    }
    CursorSpace[i].next = 0;
}

List MakeEmpty() {
    List L;
    L = CursorSpace[0].next;
    CursorSpace[0].next = CursorSpace[L].next;
    CursorSpace[L].next = 0;
    return L;
}

int IsEmpty(const List L) {
    return CursorSpace[L].next == 0;
}

int IsLast(const Position P, const List L) {
    return CursorSpace[P].next == 0;
}

Position Find(ElementType X, List L) {//找不到就返回0
    Position P = CursorSpace[L].next;
    while (P != 0 && CursorSpace[P].element != X) {
        P = CursorSpace[P].next;
    }
    return P;
}

Position FindPrevious(ElementType X, const List L) {//没找到就返回最后一个元素
    Position P = L;
    while (CursorSpace[P].next != 0 && CursorSpace[CursorSpace[P].next].element != X) {
        P = CursorSpace[P].next;
    }
    return P;
}

Position CursorAlloc() {//分配空间
    Position P = CursorSpace[0].next;
    CursorSpace[0].next = CursorSpace[P].next;
    return P;
}

void CursorFree(Position P) {//销毁空间
    CursorSpace[P].next = CursorSpace[0].next;
    CursorSpace[0].next = P;
}

void Delete(ElementType X, List L) {
    Position P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        Position tmp = CursorSpace[P].next;
        CursorSpace[P].next = CursorSpace[tmp].next;
        CursorFree(tmp);
    }
}

void Insert(ElementType X, List L, Position P) {
    Position tmp = CursorAlloc();
    CursorSpace[tmp].element = X;
    CursorSpace[tmp].next = CursorSpace[P].next;
    CursorSpace[P].next = tmp;
}

void DeleteList(List L) {
    Position tmp1 = L;
    Position tmp2;
    while (tmp1) {
        tmp2 = CursorSpace[tmp1].next;
        CursorFree(tmp1);
        tmp1 = tmp2;
    }
}

Position First(const List L) {
    return CursorSpace[L].next;
}
/*
Position Advance(const Position P) {
    
}*/

ElementType Retrieve(const Position P) {
    return CursorSpace[P].element;
}

void PrintList(List L) {
    Position tmp = CursorSpace[L].next;
    while (tmp) {
        cout << CursorSpace[tmp].element << endl;
        tmp = CursorSpace[tmp].next;
    }
}

int main()
{
    InitializeCursorSpace();//初始化"内存"
    List L = MakeEmpty();
    Position tmp = L;
    for (int i = 0; i < 8; i++) {
        Insert(i, L, tmp);
        tmp = CursorSpace[tmp].next;
    }
    PrintList(L);
    Delete(5, L);
    cout << "2nd:" << endl;
    PrintList(L);
    DeleteList(L);

    getchar();
    return 0;
}