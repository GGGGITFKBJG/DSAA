//链表
class Node {
public:
    int element;
    Node* next;
};

Node* makeEmpty(Node* list);//创建头
bool isEmpty(Node* list);
bool isLast(Node* list, Node* pos);
Node* findElement(Node* list, int element);//查找第一个
void deleteElement(Node* list, int element);
Node* findPrevious(Node* list, int element);
void insertElement(Node* list, Node* pos, int element);//在pos后插入
void deleteList(Node* list);
Node* getNode(Node* list, int i);//得到第i个节点，表头是第0个
void printList(Node* header);

Node* makeEmpty() {
    Node* header = new Node;
    header->element = 0;
    header->next = nullptr;
    return header;
}

bool isEmpty(Node* list) {
    return list->next == nullptr;
}

bool isLast(Node* list, Node* pos) {
    return pos->next == nullptr;
}

Node* findElement(Node* list, int element) {
    Node* tmp = list->next;
    while (tmp != nullptr && tmp->element != element) {
        tmp = tmp->next;
    }
    return tmp;
}

Node* findPrevious(Node* list, int element) {
    Node* tmp = list;
    while (tmp->next != nullptr && tmp->next->element != element) {
        tmp = tmp->next;
    }
    if (isLast(list, tmp)) tmp = nullptr;
    return tmp;
}

void deleteElement(Node* list, int element) {
    Node* tmp = findPrevious(list, element);
    if (tmp != nullptr) {
        Node* nodeToDelete = tmp->next;
        if(tmp->next->next != nullptr) tmp->next = tmp->next->next;
        delete nodeToDelete;
    }
}

void insertElement(Node* list, Node* pos, int element) {
    Node* tmp = new Node;
    tmp->element = element;
    tmp->next = pos->next;
    pos->next = tmp;
}

void deleteList(Node* list) {
    Node *tmp, *currentNode;
    tmp = list->next;
    list->next = nullptr;
    while (tmp != nullptr) {
        currentNode = tmp;
        tmp = tmp->next;
        delete currentNode;
    }
}

Node* getNode(Node* list, int i) {
    Node* tmp = list;
    while (i-- > 0 && tmp != nullptr) {
        tmp = tmp->next;
    }
    return tmp;
}

void printList(Node* header) {
    Node* tmp = header->next;
    while (tmp != nullptr) {
        std::cout << tmp->element << std::endl;
        tmp = tmp->next;
    }
}

#include <iostream>
using namespace std;

int main()
{
    Node* list1 = makeEmpty();
    for (int i = 0; i < 10; i++) {
        insertElement(list1, getNode(list1, i), i);
    }
    //printList(list1);
    deleteElement(list1, 6);
    printList(list1);
    deleteList(list1);
    getchar();
    return 0;
}