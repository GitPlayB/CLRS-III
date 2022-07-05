//
// Created by 陆离光怪 on 2022/5/4.
//

#include <iostream>
#include <vector>
using namespace std;

const int kLen = 10;

/**
 *
 * @param array，长度为n。数组A从[0...n-1]保存元素，
 */
void InsertionSort(int * array) {
    for (int i = 1; i < kLen; i++) {
        int key = array[i];   // 保存"待比较对象"的副本
        int j = i - 1;
//        for (int j = i - 1; j >= 0; j--) {
//            if (array[j] > key) {   // 非降序排列，直到遇见比当前小的，即插入位置
//                array[j + 1] = array[j];
//            }
//        }
        // 这里用for循环会比较麻烦，因为循环体里的判断是是否需要往后移动元素。
        // 当某个元素不满足条件后，应立即跳出循环，使用while+多个条件判断比较常见
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void PrintArray(int * array) {
    for (int i = 0; i < kLen; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[10]  = {2, 5, 7, 3, 6, 8, 4, 9, 0, 1};
    InsertionSort(array);
    PrintArray(array);

    return 0;
}