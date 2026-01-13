#include "sort.h"

void select_sort(int nums[], int n) {
    if (nums == nullptr) {
        return;
    }
    // 从[i, n)索引范围内(元素无序)选出一个最小的元素，置于i-1，[0, i)是有序元素的区间
    // 更新有序元素索引边界
    // 1个元素肯定有序
    for (int i = 1; i < n; ++i) { 
        int min_num = nums[i-1], min_idx = i-1;
        for (int j = i; j < n; ++j) {
            if (nums[j] < min_num) {
                min_idx = j;
                min_num = nums[j];
            }
        }
        // [i, n)范围内的最小元素已经找到
        if (min_idx != i-1) {
            nums[min_idx] = nums[i-1];
            nums[i-1] = min_num;
        }
    }   
}