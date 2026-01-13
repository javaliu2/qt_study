#include "sort.h"

void insert_sort(int nums[], int n) {
    if (nums == nullptr) {
        return;
    }
    for (int i = 1; i < n; ++i) {
        // [0, i-1]索引范围内的元素全部有序
        // 对于当前元素num=nums[i]，从索引(i-1)从后向前逐元素比较，
        // 找到第一个比num小的元素；或者索引为负数，表示num为[0,i-1]索引范围内最小的元素
        
        // 比较的时候就交换，还是说找到元素num的位置时整体移动
        // 比较的时候就交换是冒泡排序吧，后者是插入排序？
        // 采用后者实现
        int num = nums[i], j;
        for (j = i - 1; j >= 0; --j) {
            if (nums[j] < num) {
                break;
            }
        }
        // 以上循环结束的时候，[j+1]是元素num要插入的位置，[j+1,i-1]范围内的元素需要整体向后移动1个索引
        // 先移动，后赋值
        for (int k = i-1; k >= j+1; --k) {
            nums[k+1] = nums[k];
        }
        nums[j+1] = num;
    }
}
