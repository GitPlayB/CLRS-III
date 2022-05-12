//
// Created by 陆离光怪 on 2022/5/11.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * 划分子程序。
 * 划分前选定主元，这里选的是最后一个元素
 * 设定两指针i和j，i指向的元素是小于A[r]的边界，即A[i] < A[r]
 * i与j之间指向的是大于A[r]的部分，j指向当前需要划分的元素
 * @param A
 * @param p
 * @param r
 * @return
 */
int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;  // 初始化i为首元素之前的位置
    for (int j = p; j < r; j++) {   // j的变化范围：p -> r - 1
        if (A[j] <= x) {
            swap(A[++i], A[j]);
        }
    }
    swap(A[i+1], A[r]); // 将A[r]换到它应该在的位置
    return i + 1;
}

/**
 * 快排主程序
 * 递归终止条件是p < r。当最小的一次p < r时，只有两个元素，得到的q应该是后者，即q = r
 * 这样递归过程就只剩p和p，即quickSort(A, p, p);
 * @param A
 * @param p
 * @param r
 */
void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r); // 得到pivot element
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

void printArray(int * arr, int len) {
    for (int i = 1; i <= len; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int A[11];
    // 2 5 7 3 6 8 4 9 0 1
    for (int i = 1; i <= 10; i++) {
        cin >> A[i];
    }
    cout << "The initial input: {";
    printArray(A, 10);
    cout << "}" << endl;

    quickSort(A, 1, 10);
    cout << "After sort: {";
    printArray(A, 10);
    cout << "}" << endl;

    return 0;
}