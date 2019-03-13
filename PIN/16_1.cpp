#include <iostream>
#include <cstring>
using namespace std;

#define MAXSIZE 10
#define LISTINCREMENT 10
typedef struct {
    int* elem;
    int length;
    int listsize;
    int incrementsize;
} Sqlist;

Sqlist* makeList() {
    Sqlist* p = new Sqlist;
    p->elem = new int[MAXSIZE];
    p->length = 0;
    p->listsize = MAXSIZE;
    p->incrementsize = LISTINCREMENT;
    return p;
}

int InsertElem(Sqlist* p, int elem, int pos) {
    if (p == nullptr) return 0;
    if (pos < 1 || pos > p->length + 1) return 0;
    if (p->length == p->listsize) {
        int* temp = p->elem;
        p->listsize += p->incrementsize;
        p->elem = new int[p->listsize];
        memcpy(p->elem, temp, p->length * sizeof(int));
        delete[] temp;
    }
    for (int i = p->length - 1; i >= pos - 1; i--) {
        p->elem[i + 1] = p->elem[i];
    }
    p->elem[pos - 1] = elem;
    p->length += 1;
    return 1;
}

void deleteList(Sqlist* list) {
    if (list == nullptr) return;
    delete[] list->elem;
    delete list;
}

void printList(Sqlist* list) {
    if (list == nullptr) return;
    cout << endl << "elem[]: ";
    for (int i = 0; i < list->length; i++) {
        cout << " " << list->elem[i] << " ";
    }
    cout << endl;
    cout << "length: " << list->length << endl;
    cout << "listsize: " << list->listsize << endl;
}

int main() {
    Sqlist* list = makeList();
    printList(list);
    for (int i = 0; i < 15; i++) {
        InsertElem(list, i, i + 1);
        printList(list);
    }
    deleteList(list);

    getchar();
    return 0;
}