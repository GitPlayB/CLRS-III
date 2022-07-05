//
// Created by 陆离光怪 on 2022/5/6.
//

#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <time.h>
using namespace std;

const int kInf = numeric_limits<int>::max();
const int kNegInf = INT_MIN;  // int的最小值，保存在<limits.h>中
const int kNegInf2 = numeric_limits<int>::min();  // int的最小值，保存在<limits>中
int result[3] = {0, 0, kNegInf};  // 保存最大子数组结果。result[0]：左下标；result[1]：右下标；result[2]：最大和
int crossing_result[3];  // 保存最大子数组结果。result[0]：左下标；result[1]：右下标；result[2]：最大和
int left_result[3];  // 保存最大子数组结果。result[0]：左下标；result[1]：右下标；result[2]：最大和
int right_result[3];  // 保存最大子数组结果。result[0]：左下标；result[1]：右下标；result[2]：最大和
int random_big_array[100000];


void CopyArray(const int from[], int to[], int len) {
    for (int i = 0; i < len; i++) {
        *(to + i) = *(from + i);
    }
}

// 计算跨越中点的子数组的最大和。从中点分别向两边扫描，
// 当遇到和比之前更大时更新最大和与下标，最终结果即（left_sum + right_sum）
int * FindMaxCrossingSubarray(const int array[], int low, int mid, int high) {
    // 初始化跨越中点的最大和与下标
    int left_sum = kNegInf;
    int max_left = -1;
    int right_sum = kNegInf;
    int max_right = -1;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += array[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += array[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    crossing_result[0] = max_left;
    crossing_result[1] = max_right;
    crossing_result[2] = left_sum + right_sum;
    return crossing_result;
}

// 求解最大子数组和的分治方法
// 递归边界条件是当数组只有一个元素时；
// 其他情况，将数组划分成两半，两种情况通过递归来求解，还有一种跨越中点的用已写好的子程序来求解
// 对三种情况得到的和进行比较，得到最大和
int * FindMaxSubarray(int array[], int low, int high) {
    if (low == high) {
        result[0] = result[1] = low;
        result[2] = array[low];
        return result;
    } else {
        int mid = (low + high) / 2;
        int left_r[3], right_r[3];
        FindMaxSubarray(array, low, mid); // 这里左子数组的递归结果是直接写到result数组中
        CopyArray(result, left_r, 3);  // 立刻保存一份左子数组的结果副本
        FindMaxSubarray(array, mid + 1, high);    // 将右边子数组的结果写入result数组
        CopyArray(result, right_r, 3); // 保存右子数组结果副本
        FindMaxCrossingSubarray(array, low, mid, high);
        if (left_result[2] >= right_result[2] && left_result[2] >= crossing_result[2]) {
            CopyArray(left_result, result, 3);
            return result;
        } else if (right_result[2] >= left_result[2] && right_result[2] >= crossing_result[2]) {
            CopyArray(right_result, result, 3);
            return result;
        } else {
            CopyArray(crossing_result, result, 3);
            return result;
        }
    }
}

// 最大子数组和的暴力（BF）解法：时间复杂度O(n^2)
void FindMaxSubarrayBF(const int array[], int low, int high) {
    int max;
    // 这里的双重循环中j是从i开始的（而不是i+1）），每一轮计算一个新的临时最大和max
    for (int i = low; i <= high; i++) {
        max = 0;
        for (int j = i; j <= high; j++) {
            max += array[j];    // 每次从最开始的元素开始计入最大和
            if (max > result[2]) {
                result[0] = i;
                result[1] = j;
                result[2] = max;
            }
        }
    }
}

void PrintArray(int array[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 填充随机大数组（整型）
void FillRandomBigArray() {
    uniform_int_distribution<int> u(-100,100);
    default_random_engine e;
    for (int i = 0; i < 100000; i++) {
        random_big_array[i] = u(e);
    }
}


int main() {
    int array[16]  = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    FillRandomBigArray();
    PrintArray(random_big_array, 100000);

//    FindMaxSubarray(random_big_array, 0, 99999);
//    printf("(%d %d %d)\n", result[0], result[1], result[2]);
//    FindMaxSubarrayBF(random_big_array, 0, 99999);
//    printf("(%d %d %d)\n", result[0], result[1], result[2]);

    // 暴力解法和分治解法的时间差了大约1000倍（当数据量是10万的时候）
    printf("Divide-and-conquer begin:\n");
    clock_t start, finish;
    start = clock();
    FindMaxSubarray(random_big_array, 0, 99999);
    printf("(%d %d %d)\n", result[0], result[1], result[2]);
    finish = clock();
    printf("Time elapsed: %f\n", double(finish - start) / CLOCKS_PER_SEC);

    printf("Brute-Force begin:\n");
    start = clock();
    FindMaxSubarrayBF(random_big_array, 0, 99999);
    printf("(%d %d %d)\n", result[0], result[1], result[2]);
    finish = clock();
    printf("Time elapsed: %f\n", double(finish - start) / CLOCKS_PER_SEC);

    return 0;
}