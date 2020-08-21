#!/usr/bin/python3
"""Making change O(n)"""


def makeChange(coins, total):
    """Clasic Bottom-Up dynamic programming"""
    if total <= 0:
        return 0
    dp = [float('inf')] * (total + 1)
    dp[0] = 0
    coins.sort()
    for i in range(total + 1):
        for coin in coins:
            if coin > i:
                break
            if dp[i - coin] != -1:
                dp[i] = min(dp[i - coin] + 1, dp[i])
    return dp[total] if dp[total] != float('inf') else -1
