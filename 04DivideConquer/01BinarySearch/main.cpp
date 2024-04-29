#include "solve/binarySearch.hpp"
#include <vector>
#include <iostream>

int main(){
    // Test1
    std::vector<int> nums = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};
    int target = 6;

    std::cout << target << " at " << binarySearch(nums, 0, nums.size(), target) << std::endl;

    // Test2
    nums = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};
    target = 4;

    std::cout << target << " at " << binarySearch(nums, 0, nums.size(), target) << std::endl;

    // Test3
    nums = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};
    target = 36;

    std::cout << target << " at " << binarySearch(nums, 0, nums.size(), target) << std::endl;

}