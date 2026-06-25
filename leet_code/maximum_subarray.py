"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-25 21:37:03
**************************************************************************
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
    def maxSubArray(self, nums: list[int]) -> int:
        n = len(nums)
        ret = nums[0]
        sum = nums[0]
        for i in range(1, n):
            sum = max(sum + nums[i], nums[i])
            ret = max(ret, sum)
        return ret

def solve():
    sol = Solution()
    nums = [5,4,-1,7,8]
    print(sol.maxSubArray(nums))

if __name__ == "__main__":
    solve()