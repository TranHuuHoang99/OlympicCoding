"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-18 22:34:06
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

def solve():
    n = int(input().rstrip())
    temp = list(map(int, input().rstrip().split()))
    arr = [0] + temp
    cnt = 0
    for index in range(1, n+1):
        if (arr[index] - index > 2):
            print("Too chaotic")
            return
        for i in range(max(1, arr[index] - 2), index):
            if (arr[index] < arr[i]): cnt += 1
    print(cnt)
    pass

if __name__ == "__main__":
    t = int(input().rstrip())
    for _ in range(t):
        solve()