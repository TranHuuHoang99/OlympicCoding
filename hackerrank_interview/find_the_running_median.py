"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-24 23:12:35
**************************************************************************
"""
from collections import deque, Counter, defaultdict
import heapq
import bisect
import math
import sys
import os
from functools import cmp_to_key
# set recursion limit
sys.setrecursionlimit(int(2e5))

def solve(n: int, arr: list[int]):
    heapleft = []
    heapright = []
    ret: list[str] = []
    for a in arr:
        heapq.heappush(heapleft, -a)
        heapq.heappush(heapright, -heapq.heappop(heapleft))
        if len(heapleft) < len(heapright):
            heapq.heappush(heapleft, -heapq.heappop(heapright))
        ans = 0.0
        if len(heapleft) > len(heapright):
            ans = float(-heapleft[0])
        else:
            ans = float(-heapleft[0]) + float(heapright[0])
            ans /= 2.0
        ret.append(str(ans))
    return ret

if __name__ == "__main__":
    # handle input
    # ----------------------------------------------------
    input = sys.stdin.readline
    n = int(input().rstrip())
    arr = []
    for _ in range(n):
        arr.append(int(input().rstrip()))
    # ----------------------------------------------------
    ret: list[str] = solve(n, arr)
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    fptr.write('\n'.join(ret))
    fptr.close()
