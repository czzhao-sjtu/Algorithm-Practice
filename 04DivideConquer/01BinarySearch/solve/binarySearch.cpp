#include <vector>
#include "binarySearch.hpp"

int binarySearch(std::vector<int> &nums, int i, int j, int target){
    if (i > j) return -1;

    int m = (i + j) / 2;
    if (nums[m] > target)
        return binarySearch(nums, i, m - 1, target);
    else if (nums[m] < target)
        return binarySearch(nums, m + 1, j, target);
    else
        return m;
}
