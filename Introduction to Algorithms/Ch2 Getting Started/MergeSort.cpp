//
// Created by 陆离光怪 on 2022/5/5.
//

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100;
const int len = 10;
const int INF = (2LL << 30) - 1;  // 32位的int最大值：2^31 - 1


/**
 * 归并子程序
 * @param A 数组，将被分割为A[p...q], A[q + 1...r]
 * @param p 数组A分割后的low位置
 * @param q 数组A分割后的mid位置
 * @param r 数组A分割后的high位置
 */
void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];   // 保存分开后的两个子数组
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[q + 1 + i];
    }
    // 设置哨兵，作为结束的标志
    L[n1] = INF;
    R[n2] = INF;
    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

// merge函数的一般写法
void merge2(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];   // 保存分开后的两个子数组
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[q + 1 + i];
    }
    // 设置哨兵，作为结束的标志
    L[n1 + 1] = INF;
    L[n2 + 1] = INF;

    // 循环也可以用while
    // 但是此种写法会导致跳出循环时，有一个指针还没有直到尽头，需要遍历一下
    // 实际上是因为：没有哨兵！
    int i = 0;
    int j = 0;
    int k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[i]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[i];
            j++;
        }
        k++;
    }
    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
}

/**
 * 此方法作用是通过递归调用自身，将数组无限切分
 * 切分完毕，调用merge方法，自下而上地合并
 * @param A 数组
 * @param p 数组待排序左边界low
 * @param r 数组待排序右边界high
 */
void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void printArray(int A[]) {
    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[10]  = {2, 5, 7, 3, 6, 8, 4, 9, 0, 1};
    mergeSort(A, 0, 9);
    printArray(A);

    return 0;
}