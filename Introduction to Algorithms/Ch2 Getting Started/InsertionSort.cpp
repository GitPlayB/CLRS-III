//
// Created by 陆离光怪 on 2022/5/4.
//

#include <iostream>
#include <vector>
using namespace std;

const int len = 10;

/**
 *
 * @param A，长度为n。数组A从[0...n-1]保存元素，
 */
void insertionSort(int * A) {
    for (int i = 1; i < len; i++) {
        int key = A[i];   // 保存"待比较对象"的副本
        int j = i - 1;
//        for (int j = i - 1; j >= 0; j--) {
//            if (A[j] > key) {   // 非降序排列，直到遇见比当前小的，即插入位置
//                A[j + 1] = A[j];
//            }
//        }
        // 这里用for循环会比较麻烦，因为循环体里的判断是是否需要往后移动元素。
        // 当某个元素不满足条件后，应立即跳出循环，使用while+多个条件判断比较常见
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void printArray(int * A) {
    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[10]  = {2, 5, 7, 3, 6, 8, 4, 9, 0, 1};
    insertionSort(A);
    printArray(A);

    return 0;
}