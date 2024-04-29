from typing import List
import numpy as np

def solve(coins:List[int], amt:int):
    # 1. 建立dp表 并 第0列初始化
    dp = np.zeros((len(coins) + 1, amt + 1), dtype=np.int64)
    dp[:, 0] = 1

    # 2. 动态规划
    for i in range(1, len(coins) + 1):
        for j in range(1, amt + 1):
            if j < coins[i - 1]:
                dp[i, j] = dp[i - 1, j]
            else:
                dp[i, j] = dp[i - 1, j] + dp[i, j - coins[i - 1]]
    
    return dp[-1, -1]

def main():
    print("Test 1")

    coins = [1, 2, 5]
    amt = 5

    print("amt:", amt, ", 所有的组合可能性为", solve(coins, amt))

if __name__ == "__main__":
    main()