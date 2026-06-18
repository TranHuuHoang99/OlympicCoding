"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-18 15:24:57
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
parts = input().split()
n = int(parts[0])
d = int(parts[1])
dq = deque()
for e in input().split():
    dq.append(e)
# ----------------------------------------------------

def solve():
    for _ in range(d):
        if dq:
            val = dq[0]
            dq.popleft()
            dq.append(val)
    while dq:
        print(dq[0], end=" ")
        dq.popleft()
    pass

if __name__ == "__main__":
    solve()