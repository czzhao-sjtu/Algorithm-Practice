import numpy as np

def solve(s: str, t: str):
    n, m = len(s), len(t)
    dp = np.zeros((n+1, m+1), dtype=np.int64)
    
    #init dp
    for i in range(1, n+1):
        dp[i, 0] = i

    for j in range(1, m+1):
        dp[0, j] = j

    #dyna prog
    for i in range(1, n+1):
        for j in range(1, m+1):
            if s[i-1] == t[j-1]:
                dp[i, j] = dp[i-1, j-1]
            else:
                dp[i, j] = min(dp[i-1, j-1], dp[i-1, j], dp[i, j-1]) + 1
    
    return dp[n, m]

def main():
    print("Test 1")

    s = 'hello'
    t = 'algo'

    print(s, " -> ", t, "的最小编辑距离是：", solve(s, t))

    print("Test 2")

    s = 'kitten'
    t = 'sitting'

    print(s, " -> ", t, "最小编辑距离是：", solve(s, t))

    print("Test 3")

    s = ''
    t = 'sitting'

    print(s, " -> ", t, "最小编辑距离是：", solve(s, t))

if __name__ == "__main__":
    main()