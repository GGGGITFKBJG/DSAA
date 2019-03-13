//多项式ADT
#include <initializer_list>
#include <iostream>
using namespace std;

typedef class Node* Polynomial;//多项式
class Node {
public:
    Node() = default;
    Node(int coef, int ept) : coefficient(coef), exponent(ept) {};

    int coefficient;//系数
    int exponent;//指数
    Node* next;
};

Polynomial CreatPolynomial(initializer_list<int> inil) {
    if (inil.size() % 2 != 0) return nullptr;
    Polynomial pol = new Node;
    Node* tmp = pol;
    for (auto beg = inil.begin(); beg != inil.end(); beg += 2) {
        tmp->next = new Node(*beg, *(beg + 1));
        tmp = tmp->next;
    }
    return pol;
}

void PrintPol(Polynomial pol) {
    bool first = true;
    for (Node* tmp = pol->next; tmp != nullptr; tmp = tmp->next) {
        if (first) {
            cout << tmp->coefficient;
            first = false;
        }
        else cout << " + " << tmp->coefficient;
        if(tmp->exponent != 0) cout << "x^" << tmp->exponent;
    }
    cout << endl;
};

void DeletePol(Polynomial pol) {
    Node* tmp = pol;
    Node* tmp2;
    while (tmp != nullptr) {
        tmp2 = tmp->next;
        delete tmp;
        tmp = tmp2;
    }
}

Polynomial AddPol(Polynomial pol1, Polynomial pol2) {//应保证pol1和pol2是格式化的
    Polynomial pol3 = new Node;
    Node* tmp = pol3;
    Node* tmp1 = pol1->next;
    Node* tmp2 = pol2->next;
    int  c1, c2, e1, e2;
    while (tmp1 != nullptr && tmp2 != nullptr) {
        c1 = tmp1->coefficient;
        c2 = tmp2->coefficient;
        e1 = tmp1->exponent;
        e2 = tmp2->exponent;
        if (e1 == e2) {
            tmp->next = new Node(c1 + c2, e1);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        else if (e1 > e2) {
            tmp->next = new Node(c1, e1);
            tmp1 = tmp1->next;
        }
        else {
            tmp->next = new Node(c2, e2);
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    return pol3;
};

void FormatPol(Polynomial pol) {//按指数从大到小格式化
    //先排序再合并
    Node* tmp1 = pol;
    Node* tmp2;
    Node* maxNode;
    while (tmp1->next != nullptr) {
        tmp2 = tmp1->next;
        maxNode = tmp1;
        while (tmp2->next != nullptr) {
            if (tmp2->next->exponent > maxNode->next->exponent) maxNode = tmp2;
            tmp2 = tmp2->next;
        }
        if (tmp1 != maxNode) {//交换maxNode.next和tmp1.next
            Node* tmpSwap1 = tmp1->next;
            Node* tmpSwap2 = maxNode->next;
            if (tmp1->next != maxNode) {
                tmp1->next = tmp1->next->next;
                maxNode->next = tmpSwap1;
                tmpSwap1->next = tmpSwap2->next;

                tmpSwap2->next = tmp1->next;
                tmp1->next = tmpSwap2;
            }
            else {//相邻的情况
                tmp1->next = tmp1->next->next;
                tmpSwap1->next = tmpSwap2->next;
                tmpSwap2->next = tmpSwap1;
            }
        }
        tmp1 = tmp1->next;
    }

    //合并同类项
    tmp1 = pol->next;
    tmp2 = tmp1->next;
    while (tmp2 != nullptr) {
        if (tmp1->exponent == tmp2->exponent) {
            tmp1->coefficient += tmp2->coefficient;
            tmp1->next = tmp2->next;
            delete tmp2;
            tmp2 = tmp1->next;
        }
        else {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }

    //删除系数为0的项
    tmp1 = pol;
    while (tmp1 != nullptr && tmp1->next != nullptr) {
        if (tmp1->next->coefficient == 0) {
            tmp2 = tmp1->next;
            tmp1->next = tmp1->next->next;
            delete tmp2;
        }
        tmp1 = tmp1->next;
    }
}

Polynomial MultPol(Polynomial pol1, Polynomial pol2) {
    Polynomial pol3 = new Node;
    Node* tmp = pol3;
    Node* tmp1 = pol1->next;
    Node* tmp2;
    while (tmp1 != nullptr) {
        tmp2 = pol2->next;
        while (tmp2 != nullptr) {
            tmp->next = new Node(tmp1->coefficient * tmp2->coefficient, tmp1->exponent + tmp2->exponent);
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
    //先乘再格式化
    FormatPol(pol3);
    return pol3;
}

int main()
{
    Polynomial pol1 = CreatPolynomial({ 2,2,4,1,4,2,3,3,1,0 });
    Polynomial pol2 = CreatPolynomial({ 2,3,3,1,-2,0 });
    FormatPol(pol1);
    FormatPol(pol2);
    //Polynomial pol3 = AddPol(pol1, pol2);
    Polynomial pol4 = MultPol(pol1, pol2);
    PrintPol(pol1);
    PrintPol(pol2);
    PrintPol(pol4);

    DeletePol(pol1);
    DeletePol(pol2);
    DeletePol(pol4);

    getchar();
    return 0;
}