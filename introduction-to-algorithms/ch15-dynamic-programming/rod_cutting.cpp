//
// Created by 陆离光怪 on 2022/5/20.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 切割绳子/钢条的算法在分析时，首先把需要划分两边的子问题改为只需要划分一边的子问题
 * 即一个规模为n的问题划分为r(i)和r(n-i)(i = 1, 2, ... , n)需要考虑两段子问题，
 * 而只考虑一边也可以，即将规模为n的问题划分为p(i)和r(n-i)(i = 1, 2, ... , n)，其中p[i]是指左边长度为i的钢条完整保留（不切割）
 * 后者的划分是正确的，因为对于规模为n的问题，求解的结果同样会是2^(n-1)种结果，
 * 其结果是「左边固定长度（可称作"第一段"）取遍n-1个位置+剩下部分长度的子问题最优值」之和，
 * 即max{p(i)+r(n-i)}(i = 1, 2, ... , n)
 */

const int kLen = 10;
const int kNegInf = INT_MIN;  // int的最小值，保存在<limits.h>中

// 暴力的递归写法
int CutRod(int p[], int n) {
    if (n == 0) return 0;
    int q = kNegInf;  // q初始化为-∞
    for (int i = 1; i <= n; i++) {
        q = max(q, p[i] + CutRod(p, n - i));
    }
    return q;
}

// 带备忘录的自顶向下法-辅助函数
// p 「长度-价格」数组
// n 长度，即问题规模
// r 备忘录，保存对应输入规模为0-n时的最优值
// n 最优值
int MemorizedCutRodAux(int p[], int n, int r[]) {
    if (r[n] >= 0) return r[n]; // 递归出口变为检查r[n]是否已计算好
    int q;
    if (n == 0) q = 0;  // 这里原本是递归出口（要返回的），改为一个简单的赋值操作
    else q = kNegInf;
    for (int i = 1; i <= n; i++) {
        q = max(q, p[i] + MemorizedCutRodAux(p, n - i, r));
    }
    r[n] = q;   // 当问题规模n变为0时，会将q = 0设置并赋值给r[0]
    return q;
}

// 动态规划一：带备忘录的自顶向下法
int MemorizedCutRod(int p[], int n) {
    int r[n + 1];   // 数组r存储元素0 <= i <= n，保存对应输入规模为0-n时的最优值
    for (int i = 0; i <= n; i++) {
        r[i] = kNegInf;   // 初始化r[i]为-∞
    }
    return MemorizedCutRodAux(p, n, r);
}

// 动态规划二：自底向上法
int BottomUpCutRod(int p[], int n) {
    int r[n + 1];   // 数组r存储元素0 <= i <= n，保存对应输入规模为0-n时的最优值
    r[0] = 0;
    int q = kNegInf;  // q初始化为-∞
    // 双重for循环的复杂度为一个等差数列的和（O(n^2)）
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            q = max(q, p[j] + r[i - j]);    // 计算当问题规模为i，第一段（固定）长度为j时的最优值
        }
        r[i] = q;   // 当问题规模为i时，最优值为r[i]
    }
    return r[n];
}

void PrintArray(int * arr, int kLen) {
    for (int i = 1; i <= kLen; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int p[11];  // 1-10存储元素
    // 1 5 8 9 10 17 17 20 24 30
    for (int i = 1; i <= kLen; i++) {
        scanf("%d", &p[i]);
    }
    int q1 = CutRod(p, 10);
    printf("{CutRod} The max profit would be: %d\n", q1);
    int q2 = MemorizedCutRod(p, 10);
    printf("{memorizedCutRod} The max profit would be: %d\n", q2);
    int q3 = BottomUpCutRod(p, 10);
    printf("{bottomUpCutRod} The max profit would be: %d\n", q3);

    return 0;
}