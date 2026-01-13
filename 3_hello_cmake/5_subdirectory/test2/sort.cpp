#include <iostream>
#include "sort.h"

int main() {
    using namespace std;
    int nums[] = {9, -2, -5, 4, 3, 10, 23, 56, -100,  23, 5};
    select_sort(nums, sizeof(nums) / sizeof(nums[0]));
    cout << "select sort result: ";
    for (int num : nums) {
        cout << num << " ";
    }

    int nums2[] = {5, 3, 2, 0, -1, -12};
    insert_sort(nums2, sizeof(nums2) / sizeof(nums2[0]));
    cout << "insert sort result: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    return 0;
}