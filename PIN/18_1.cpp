//图的构建(邻接链表法), 遍历, DFS, BFS
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

#define MAX_VERTEX_NUM 10
typedef char VertexType;

typedef struct ENode {//边结点类型
    int adjvex;
    ENode *next;
} *PtrtoENode;

typedef struct VNode {//顶点节点类型
    VertexType data;
    ENode *firstEdge;
} *PtrtoVNode;

VNode G[MAX_VERTEX_NUM];//图

void creatGraph(VNode *g, int n) {
    char c;
    int index;
    for (int i = 0; i < n; i++) {
        cout << "Input a Vertex: " << endl;
        cin >> c;
        g[i].data = c;//顶点数据
        g[i].firstEdge = nullptr;
        cout << "Input Edges: " << endl;
        while (cin >> index && index != -1) {//边结点
            PtrtoENode p = new ENode;
            p->adjvex = index;
            p->next = g[i].firstEdge;
            g[i].firstEdge = p;
        }
    }
    cout << "Build graph successfully." << endl;
}

void freeGraph(VNode *g, int n) {
    PtrtoENode p;
    for (int i = 0; i < n; i++) {
        while (g[i].firstEdge != nullptr) {
            p = g[i].firstEdge;
            g[i].firstEdge = p->next;
            delete p;
        }
    }
}

int visited[MAX_VERTEX_NUM];//访问记录

void DFS(VNode *g, int v) {
    cout << g[v].data << " ";
    visited[v] = 1;
    PtrtoENode p = g[v].firstEdge;//第一个邻接顶点
    while (p != nullptr) {
        if(visited[p->adjvex] == 0) DFS(g, p->adjvex);
        p = p->next;
    }
}

void DFS_main(VNode *g, int n) {//初始化visited, 开始DFS
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) DFS(g, i);
    }
    cout << endl;
}

void BFS(VNode *g, int v) {
    cout << g[v].data << " ";
    visited[v] = 1;
    queue<PtrtoVNode> q;
    q.push(&g[v]);
    while (!q.empty()) {
        PtrtoVNode pv = q.front();
        q.pop();
        PtrtoENode pe = pv->firstEdge;
        int index;
        while (pe != nullptr) {
            index = pe->adjvex;
            if (visited[index] == 0) {
                cout << g[index].data << " ";
                visited[index] = 1;
                q.push(&g[index]);
            }
            pe = pe->next;
        }
    }
}

void BFS_main(VNode *g, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) BFS(g, i);
    }
    cout << endl;
}

int main() {
    creatGraph(G, 5);
    DFS_main(G, 5);
    BFS_main(G, 5);
    freeGraph(G, 5);
    system("pause");
    return 0;
}
