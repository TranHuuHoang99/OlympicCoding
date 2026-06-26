"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-26 11:29:25
**************************************************************************
"""
from collections import deque, Counter, defaultdict
import heapq
import bisect
import math
import sys
from functools import cmp_to_key
input = sys.stdin.readline

def solve():
    n = int(input().rstrip())
    A: list[list] = [[0,0]]
    for i in range(n):
        u, v = map(int, input().rstrip().split())
        A.append([u, v])
    pre_left: list = [0 for _ in range(n+5)]
    suf_left: list = [0 for _ in range(n+5)]
    pre_right: list = [int(1e9) for _ in range(n+5)]
    suf_right: list = [int(1e9) for _ in range(n+5)]
    for i in range(1, n+1):
        pre_left[i] = max(pre_left[i-1], A[i][0])
        pre_right[i] = min(pre_right[i-1], A[i][1])
    for i in range(n, 0, -1):
        suf_left[i] = max(suf_left[i+1], A[i][0])
        suf_right[i] = min(suf_right[i+1], A[i][1])
    ret = 0
    for i in range(1, n+1):
        # we remove the segment i
        max_left = max(pre_left[i-1], suf_left[i+1])
        # we remove the segment i
        min_right = min(pre_right[i-1], suf_right[i+1])
        ret = max(ret, min_right - max_left)
    print(ret)

if __name__ == "__main__":
    solve()

