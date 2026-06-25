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
        total_profit = 0
        effect = prices[0] + fee
        for i in range(1, n):
            cur_price = prices[i]
            # if stock is down, we should wait ultil to day to buy
            # or we end previous trasition and start buy it from today
            if cur_price + fee < effect:
                effect = cur_price + fee
            elif effect < prices[i]:
                total_profit += prices[i] - effect
                # not sure today is a good profit to sell
                # maybe tomorrow stock will raise higher, so we remain the effect
                # priceA < priceB < priceC
                # transition today : priceB - priceA - fee
                # priceC > priceB
                # we dont sell at day B, we sell at day C
                # priceC (- priceB + priceB) - priceA - fee
                effect = prices[i]
        return total_profit

def solve():
    sol: Solution = Solution()
    prices = [1,3,2,8,4,9]
    fee = 2
    print(sol.maxProfit(prices, fee))

if __name__ == "__main__":
    solve()