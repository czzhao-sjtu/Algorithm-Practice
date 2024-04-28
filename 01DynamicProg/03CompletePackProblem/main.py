import numpy as np

def solution(weights, values, capability: int):
    assert len(weights) == len(values)

    dp = np.zeros(capability + 1)
    
    for c in range(min(weights), capability + 1):
        valid_item_idx = [idx for idx, weight in enumerate(weights) if weight <= c]
        dp[c] = max(dp[c - weights[idx]] + values[idx] for idx in valid_item_idx)
    
    return dp[-1]

def main():
    print("Test 1")

    weights = [10, 20, 30, 40, 50]
    values = [50, 120, 150, 210, 240]
    capability:int = 50

    print(solution(weights, values, capability))

    print("Test 2")

    weights = [1, 3, 4]
    values = [15, 20, 30]
    capability:int = 4

    print(solution(weights, values, capability))    

if __name__ == "__main__":
    main()