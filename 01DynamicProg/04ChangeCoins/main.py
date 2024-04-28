from typing import List
import numpy as np

def solve(coins:List[int], amt: int):
    dp = np.zeros(amt + 1, dtype=np.int64)
    previous_amounts = np.ones(amt + 1, dtype=np.int64)
    
    # 前向计算
    for c in range(1, amt + 1):
        valid_coin_idx = [idx for idx, coin in enumerate(coins) if c - coin >= 0]

        dp_ = np.array([dp[c - coins[idx]] for idx in valid_coin_idx])
        previous_amounts[c] = c - coins[dp_.argmin()]
        dp[c] = dp_.min() + 1
    
    # 回溯求解的路径
    result = []
    c = amt
    while(c != 0):
        previous_amount = previous_amounts[c]
        result.append(c - previous_amount)
        c = previous_amount

    return dp[-1], result

def main():
    
    print("Test 1")
    coins = [1, 2, 5]
    amt = 11
    min_num, result = solve(coins, amt)
    print("最小数量为:", min_num)
    print("由这些硬币组成:", result)

    print("Test 2")
    coins = [1, 2, 5]
    amt = 13
    min_num, result = solve(coins, amt)
    print("最小数量为:", min_num)
    print("由这些硬币组成:", result)

    print("Test 3")
    coins = [1, 2, 5]
    amt = 15
    min_num, result = solve(coins, amt)
    print("最小数量为:", min_num)
    print("由这些硬币组成:", result)

if __name__ == "__main__":
    main()