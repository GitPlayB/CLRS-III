//
// Created by 陆离光怪 on 2022/7/5.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 这里的Node定义包含了所有可能的属性，可作为一种「大而全」的实现方式
// [注]：这里的pre就是原书上的π
// 例如，和每个结点相关联的属性d可以不用，而是使用一个额外的int数组来保存；
//      和每个结点相关联的属性pre可以不用，而是使用一个额外的int数组来保存；
// 这里d和pre都是和结点相关联的属性（color也是的），按照《算法笔记》或别的实现，也可以单独用一个数组来保存。
typedef struct Node {
    int v;  // 邻接边的目标顶点
    int dis;    // 邻接边的边权
    int color;  // 0(WHITE): 未入队 1(GRAY): 已入队未访问 2(BLACK): 已入队已访问
    int d;  // 层数，或距离起点s的最短距离
    int pre;    // 前驱结点编号
} Vertex;

const int kMax = 1010;  // kMax为最大顶点数
int n;    // n为图的顶点数
const int kInf = 0x3f3f3f3f;
Vertex nodes[kMax];
vector<Vertex> Adj[kMax];   // 邻接表表示
Vertex G[kMax][kMax];   // 邻接矩阵表示

void BFS(int s) {
    for (int i = 0; i < n; i++) {
        nodes[i].color = 0;
        nodes[i].d = kInf;
        nodes[i].pre = -1;
    }
    Vertex start;
    start.color = 1;
    start.d = 0;
    start.pre = -1;
    queue<Vertex> q;
    q.push(start);
    while (!q.empty()) {
        Vertex top = q.front();
    }
}

void DFS() {

}

int main() {

    return 0;
}

