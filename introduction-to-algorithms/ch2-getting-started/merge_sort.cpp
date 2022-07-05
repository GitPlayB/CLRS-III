//
// Created by 陆离光怪 on 2022/5/5.
//

#include <iostream>
#include <vector>
using namespace std;

const int kLen = 10;
const int kInf = (2LL << 30) - 1;  // 32位的int最大值：2^31 - 1


/**
 * 归并子程序
 * 归并排序的过程是要花费O(n)的空间复杂度的，要保存排序后的结果
 * 可以新建一个数组（在全局，即子程序外面），然后用两个指针指向原数组的相应位置即可
 * 或者直接用原有的数组来存排序后的元素，不过要建立两个数组存放被分成两半的子数组
 * @param array 数组，将被分割为A[p...q], array[q + 1...r]
 * @param p 数组A分割后的low位置
 * @param q 数组A分割后的mid位置
 * @param r 数组A分割后的high位置
 */
// 归并子程序
// 归并排序的过程是要花费O(n)的空间复杂度的，要保存排序后的结果
// 可以新建一个数组（在全局，即子程序外面），然后用两个指针指向原数组的相应位置即可
// 或者直接用原有的数组来存排序后的元素，不过要建立两个数组存放被分成两半的子数组
// 数组array将被分割为A[p...q], array[q + 1...r]
void Merge(int array[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    // 保存分开后的两个子数组
    int left[n1 + 1], right[n2 + 1];
    for (int i = 0; i < n1; i++) {
        left[i] = array[p + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = array[q + 1 + i];
    }
    // 设置哨兵，作为结束的标志
    left[n1] = kInf;
    right[n2] = kInf;
    int i = 0;
    int j = 0;

    // 一边排序，一边把排序结果写回到原数组的"对应位置"
    // 这也是为什么说归并排序是原址排序的原因
    for (int k = p; k <= r; k++) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
    }
}

// merge函数的一般写法
void Merge2(int array[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[n1], right[n2];   // 保存分开后的两个子数组
    for (int i = 0; i < n1; i++) {
        left[i] = array[p + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = array[q + 1 + i];
    }

    // 循环也可以用while
    // 但是此种写法会导致跳出循环时，有一个指针还没有指到尽头，需要遍历一下
    // 实际上是因为：没有哨兵！（即，此方式用多余的两个while循环替代了哨兵）
    int i = 0;
    int j = 0;
    int k = p;
    while (i < n1 && j < n2) {
        if (left[i] <= right[i]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[i];
            j++;
        }
        k++;
    }
    while (i < n1) array[k++] = left[i++];
    while (j < n2) array[k++] = right[j++];
}

/**
 * 此方法作用是通过递归调用自身，将数组无限切分
 * 切分完毕，调用merge方法，自下而上地合并
 * @param array 数组
 * @param p 数组待排序左边界low
 * @param r 数组待排序右边界high
 */
void MergeSort(int array[], int p, int r) {
    if (p < r) {    // 当只有小于等于1个元素时，无需排序（划分+合并）
        int q = (p + r) / 2;
        MergeSort(array, p, q);
        MergeSort(array, q + 1, r);
        Merge(array, p, q, r);
    }
}

void PrintArray(int array[]) {
    for (int i = 0; i < kLen; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[10]  = {2, 5, 7, 3, 6, 8, 4, 9, 0, 1};
    MergeSort(array, 0, 9);
    PrintArray(array);

    return 0;
}