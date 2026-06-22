"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-22 22:57:04
**************************************************************************
"""
from collections import deque, Counter, defaultdict
import heapq
import bisect
import math
import sys
from functools import cmp_to_key
# set recursion limit
sys.setrecursionlimit(int(2e5))
# handle input
# ----------------------------------------------------
input = sys.stdin.readline
# ----------------------------------------------------

class Solution:
    def cmp(self, a: list[int], b: list[int]):
        if a[0] != b[0]:
            return -1 if a[0] < b[0] else 1
        if a[1] != b[1]:
            return 1 if a[1] < b[1] else -1
        return 0
    def maxEnvelopes(self, envelopes: list[list[int]]) -> int:
        envelopes.sort(key=cmp_to_key(self.cmp))
        tail = []
        for pair in envelopes:
            val = pair[1]
            idx = bisect.bisect_left(tail, val)
            if idx == len(tail):
                tail.append(val)
            else:
                tail[idx] = val
        return len(tail)

def solve():
    envelopes = [[5,4],[6,4],[6,7],[2,3]]
    sol = Solution()
    ret = sol.maxEnvelopes(envelopes=envelopes)
    print(ret)
    pass

if __name__ == "__main__":
    solve()