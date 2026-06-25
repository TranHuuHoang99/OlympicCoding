"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-25 21:50:45
**************************************************************************
PROBLEM'S NAME: Best Time to Buy and Sell Stock with Transaction Fee
"""
from collections import deque, Counter, defaultdict
import heapq
import bisect
import math
import sys
import os
from functools import cmp_to_key
# ----------------------------------------------------
input = sys.stdin.readline
# ----------------------------------------------------

class Solution:
    def maxProfit(self, prices: list[int], fee: int) -> int:
        n = len(prices)
        # f[i'th stock][state = 0 mean empty, state = 1 mean holding]
        INF = int(-2e9)
        f = [[int(INF) for _ in range(2)] for _ in range(n+10)]
        f[0][0] = 0
        prices = [0] + prices
        for i in range(n):
            for state in range(2):
                if f[i][state] == INF: continue
                if state == 0: # if currently we have no stock to sell
                    # if we decide to buy stock on the next price
                    f[i+1][1] = max(f[i+1][1], f[i][state] - prices[i+1])
                    # if we decide not to buy stock on the next price
                    f[i+1][0] = max(f[i+1][0], f[i][state])
                else: # if currently we have stock to sell
                    # if we decide to sell on the next price
                    f[i+1][0] = max(f[i+1][0], prices[i+1] + f[i][state] - fee)
                    # if we decide not to sell on the next price
                    f[i+1][1] = max(f[i+1][1], f[i][state])
        return f[n][0]

def solve():
    sol: Solution = Solution()
    prices = [1,3,2,8,4,9]
    fee = 2
    print(sol.maxProfit(prices, fee))

if __name__ == "__main__":
    solve()