//
// Created by 陆离光怪 on 2022/5/10.
//

/**
 * 关于优先队列的实现，就暂不写了
 * 优先队列相对于堆的基本方法，主要多了插入、删除以及修改方法
 * 按照CLRS中的实现，
 * 【删除元素】即删除并返回当前的堆顶元素
 * 【修改元素】需要传入待修改元素的index以及新值，其中修改完元素后要进行向上调整
 * 【插入元素】利用到了修改方法，即先插入一个值为-∞的结点，然后通过修改方法改为要插入的值
 */

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100;
int len = 10; // 堆的长度
const int INF = (2LL << 30) - 1;  // 32位的int最大值：2^31 - 1
vector<int> sorted[maxn];  // 保存排序后的元素

void printArray(int * arr, int len) {
    for (int i = 1; i <= len; i++) {
        cout << arr[i] << " ";
    }
}

void printArray(vector<int> *v, int len) {
    for (int i = 1; i <= len; i++) {
        cout << v->back() << " ";
        v->pop_back();
    }
}

/**
 * 维护（最大）堆的性质
 * 操作其实就是向下调整，这里是通过递归来实现的（而不是迭代）
 * ⚠️这里《算法导论》的向下调整代码有问题，在建堆时体现不出来，在堆排序中体现出来了。
 * 因为建堆时从非叶子结点开始，自下而上地遍历结点进行向下调整，
 * 是先局部满足最大堆的性质，然后整体满足的，不会出现问题；
 * 而堆排序时，是依次将根结点与最后结点交换，取出最大值（根结点）
 * 取出的根结点是最大的，放在了最后面。之后进行向下调整的时候，如果还是比较到最后一个元素，
 * 即包含了刚刚换下去的最大元素，那么这个最大元素又会被换上去，就影响了排序过程。
 * 所以解决方法：
 * 1、把堆顶取出后扔了，即真正的删除元素（堆大小len会变小）；
 * 2、向下调整函数maxHeapify(int A[], int i)改为maxHeapify(int A[], int i, int len)，把要调整到的堆的边界传进去
 * 这里用方法一实现，方法二的写法参考《算法笔记》相关章节
 * @param A 存储堆的数组
 * @param i 从哪个位置开始向下调整
 */
void maxHeapify(int A[], int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;
    if (l <= len && A[l] > A[i]) {
        largest = l;
    }
    if (r <= len && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) { // 这里"是否交换元素"也是是否进行递归的判断依据
        swap(A[i], A[largest]);
        maxHeapify(A, largest);
    }
}

/**
 * 建堆。建堆过程就是对一个普通数组进行向下调整的过程
 * 当然，这里的"普通数组"是看作树的结构，即左子树 = 父结点 * 2，
 * 右子树 = 父结点 * 2 + 1
 * @param A 存储堆元素的数组
 */
void buildMaxHeap(int A[]) {
    for (int i = len / 2; i >= 1; i--) {
        maxHeapify(A, i);
    }
}

/**
 * 删除根结点（最大值）
 * @param A
 */
void deleteTop(int A[]) {
    A[1] = A[len--];
    maxHeapify(A, 1);
}

/**
 * 堆排序。
 * 首先建堆，然后依次取出堆顶-放入数组-向下调整
 * @param A 存储堆元素的数组
 */
void heapSort(int A[]) {
    buildMaxHeap(A);
    for (int i = len; i > 1; i--) {
        sorted->push_back(A[1]);
        deleteTop(A);
    }
    sorted->push_back(A[1]);
}

int main() {
    int A[11];
    // 2 5 7 3 6 8 4 9 0 1
    for (int i = 1; i <= len; i++) {
        cin >> A[i];
    }
    cout << "The initial input: {";
    printArray(A, 10);
    cout << "}" << endl;

    heapSort(A);
    cout << "After sort: {";
    printArray(sorted, 10);
    cout << "}" << endl;

    return 0;
}