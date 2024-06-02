from typing import List

# 问题描述：nums数组中包含重复元素，nums中每个元素只能够选取一次，从nums中选取不重复子集，使其元素和等于目标target

class Solution:
    @classmethod
    def backTracking(cls, nums: List[int], target: int) -> List[List[int]]:
        nums.sort() # 排序数组元素以在回溯中判断某个元素是否存在相等的元素
        result = []
        cls._backTracking(nums=nums, target=target, start = 0, state = [], result = result)
        return result

    @classmethod
    def _backTracking(cls, nums: List[int], target: int, start: int,
                      state: List[int], result: List[List[int]]) -> None:
        # 记录有效解
        if target == 0:
            result.append(list(state))
            return

        for idx in range(start, len(nums)):
            choice = nums[idx]

            # 剪枝
            if (choice > target):
                break
            
            if idx > start and choice == nums[idx - 1]:
                continue

            # 做选择
            state.append(choice)

            # 求解子问题
            cls._backTracking(nums, target - choice, idx + 1, state, result)

            # 撤销选择
            state.pop()

        return

class Test:
    @classmethod
    def print(cls, nums, target, solutions) -> None:
        print(f"Nums are: {nums}.")
        print(f"Target is: {target}. ")
        print(f"Solutions are as follows: 👇")

        for solution in solutions:
            print(f"\t{solution}")

        print()

    @classmethod
    def test_backtrack1(cls):
        nums = [1, 1, 2, 3, 7, 6]
        target = 8

        solutions = Solution.backTracking(nums=nums,
                                          target=target)

        cls.print(nums, target, solutions)

    @classmethod
    def test_backtrack2(cls):
        nums = [4, 4, 5]
        target = 9 

        solutions = Solution.backTracking(nums=nums,
                                          target=target)

        cls.print(nums, target, solutions)

if __name__ == "__main__":
    Test.test_backtrack1()
    Test.test_backtrack2()