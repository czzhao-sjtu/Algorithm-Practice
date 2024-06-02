from typing import List

# nums不包含重复元素，每个元素可以选择多次，返回结果不能有重复子集。
class Solution:
    @staticmethod
    def backTracking(nums: List[int], target: int) -> List[List[int]]:
        start: int = 0
        state: List[int] = []
        result:List[List[int]] = []

        Solution._backTracking(nums=nums, target=target, start=start,
                               state=state, result=result)
        
        return result

    @staticmethod
    def _backTracking(nums: List[int], target: int, start: int, 
                      state: List[int], result: List[List[int]]):
        
        if target == 0:
            result.append(list(state))
            return

        for idx in range(start, len(nums)):
            choice = nums[idx]

            # 剪枝
            if choice > target:
                continue
            
            # 前进
            state.append(choice)

            # 回溯
            Solution._backTracking(nums = nums, target = target - choice, start = idx,
                                   state = state, result = result)
            
            # 撤销
            state.pop()

        return 

class Test:
    @classmethod
    def print(cls, nums, target, solutions):
        print(f"Nums are: {nums}.")
        print(f"Target is: {target}. ")
        print(f"Solutions are as follows: 👇")

        for solution in solutions:
            print(f"\t{solution}")

        print()
    
    @classmethod
    def test_backtrack1(cls):
        nums = [3, 4, 5]
        target = 9

        result = Solution.backTracking(nums, target)
        cls.print(nums, target, result)

    @classmethod
    def test_backtrack2(cls):
        nums = [2, 3, 4, 5]
        target = 7
        solutions = Solution.backTracking(nums, target)
        cls.print(nums, target, solutions)

    @classmethod
    def test_backtrack3(cls):
        nums = [2, 3, 4, 5]
        target = 10
        solutions = Solution.backTracking(nums, target)
        cls.print(nums, target, solutions)
        

if __name__ == "__main__":
    Test.test_backtrack1()
    Test.test_backtrack2()
    Test.test_backtrack3()