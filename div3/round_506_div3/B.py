"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-25 17:49:58
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
    arr = [0] + list(map(int, input().rstrip().split()))
    arr[0] = int(-1e9)
    ret = 0
    cnt = 0
    for i in range(1, n+1):
        if arr[i] <= 2 * arr[i-1]:
            cnt += 1
        else:
            ret = max(ret, cnt)
            cnt = 1
    ret = max(ret, cnt)
    print(ret)

if __name__ == "__main__":
    solve()