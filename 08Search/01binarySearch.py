from typing import List

class BinarySearch:
    @staticmethod
    def insertPosition(nums:List[int], target:int):
        i, j = 0, len(nums) - 1

        while(i <= j):
            m = i + (j - i) // 2
            if nums[m] < target:
                i = m + 1
            elif nums[m] > target:
                j = m - 1
            else:
                j = m - 1
        
        return i

    @staticmethod
    def leftBound(nums: List[int], target: int):
        i = BinarySearch.insertPosition(nums, target)
        if (i == len(nums) or nums[i] != target):
            return -1
        return i

    @staticmethod
    def rightBound(nums: List[int], target:int):
        i = BinarySearch.insertPosition(nums, target + 1)
        j = i - 1
        if (j == -1 or nums[j] != target):
            return -1
        return j
    
class Test:
    @staticmethod
    def test_insertPosition1():
        nums = [1, 3, 6, 8, 12, 15, 23, 26, 31, 35]
        target = 6
        i = BinarySearch.insertPosition(nums, target)
        print(f"Nums: {nums}")
        print(f"Target: {target}")
        print(f"Insert Position: {i}")

    @staticmethod
    def test_insertPosition2():
        nums = [1, 3, 6, 6, 6, 6, 6, 10, 12, 15]
        target = 6
        i = BinarySearch.insertPosition(nums, target)
        print(f"Nums: {nums}")
        print(f"Target: {target}")
        print(f"Insert Position: {i}") 

    @staticmethod
    def test_insertPosition3():
        nums = [1, 3, 10, 12, 15]
        target = 6
        i = BinarySearch.insertPosition(nums, target)
        print(f"Nums: {nums}")
        print(f"Target: {target}")
        print(f"Insert Position: {i}") 

    @staticmethod
    def test_leftBound1():
        nums = [1, 3, 6, 8, 12, 15, 23, 26, 31, 35]
        target = 6
        i = BinarySearch.leftBound(nums, target)
        print(f"Nums: {nums}")
        print(f"Target: {target}")
        print(f"Left Bound: {i}") 

    @staticmethod
    def test_leftBound2():
        nums = [1, 3, 6, 6, 6, 6, 6, 10, 12, 15]
        target = 6
        i = BinarySearch.leftBound(nums, target)
        print(f"Nums: {nums}")
        print(f"Target: {target}")
        print(f"Left Bound: {i}") 

    @staticmethod
    def test_leftBound3():
        nums = [1, 3, 10, 12, 15]
        target = 6
        i = BinarySearch.leftBound(nums, target)
        print(f"Nums: {nums}")
        print(f"Target: {target}")
        print(f"Left Bound: {i}") 
        
    @staticmethod
    def test_rightBound1():
        nums = [1, 3, 6, 8, 12, 15, 23, 26, 31, 35]
        target = 6
        i = BinarySearch.rightBound(nums, target)
        print(f"Nums: {nums}")
        print(f"Target: {target}")
        print(f"Right Bound: {i}") 

    @staticmethod
    def test_rightBound2():
        nums = [1, 3, 6, 6, 6, 6, 6, 10, 12, 15]
        target = 6
        i = BinarySearch.rightBound(nums, target)
        print(f"Nums: {nums}")
        print(f"Target: {target}")
        print(f"Right Bound: {i}") 

    @staticmethod
    def test_rightBound3():
        nums = [1, 3, 10, 12, 15]
        target = 6
        i = BinarySearch.rightBound(nums, target)
        print(f"Nums: {nums}")
        print(f"Target: {target}")
        print(f"Right Bound: {i}") 
        

if __name__ == "__main__":
    Test.test_insertPosition1()
    Test.test_insertPosition2()
    Test.test_insertPosition3()
    Test.test_leftBound1()
    Test.test_leftBound2()
    Test.test_leftBound3()
    Test.test_rightBound1()
    Test.test_rightBound2()
    Test.test_rightBound3()