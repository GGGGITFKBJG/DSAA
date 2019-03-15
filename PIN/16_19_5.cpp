//队列的实现
#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
} *PtrtoNode;

struct Queue {
    PtrtoNode rear;
    PtrtoNode front;
};

Queue* makeEmpty() {
    Queue* q = new Queue;
    q->front = nullptr;
    q->rear = nullptr;
    return q;
}

void enQueue(Queue *q, int data) {
    if (q == nullptr) return;
    PtrtoNode temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if (q->front == nullptr) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

void deQueue(Queue *q) {
    if (q == nullptr) return;
    if (q->front == nullptr) return;
    PtrtoNode temp = q->front;
    q->front = temp->next;
    delete temp;
}

void deleteQueue(Queue *q) {
    if (q == nullptr) return;
    PtrtoNode p1 = q->front, p2;
    while (p1 != nullptr) {
        p2 = p1->next;
        delete p1;
        p1 = p2;
    }
}

bool isEmpty(Queue *q) {
    return q->front == nullptr;
}

int main() {
    Queue *q = makeEmpty();
    for (int i = 0; i < 11; i++) {
        enQueue(q, i);
    }
    enQueue(q, 100);
    deQueue(q);
    while (!isEmpty(q)) {
        cout << q->front->data << " ";
        deQueue(q);
    }
    cout << endl;

    deleteQueue(q);
    getchar();
    return 0;
}