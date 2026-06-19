"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-19 23:26:05
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
# handle input
# ----------------------------------------------------
input = sys.stdin.readline
n = int(input().rstrip())
arr = [0 for _ in range(n+10)]
for index in range(1, n+1):
    arr[index] = int(input().rstrip())
arr[n+1] = 0
# ----------------------------------------------------

def solve():
    f = [0 for _ in range(n+10)]
    for i in range(n+1):
        if arr[i] > arr[i-1]:
            f[i] = f[i-1] + 1
        elif arr[i] == arr[i-1]:
            f[i] = min(1, f[i-1])
        else:
            f[i] = 1
    for i in range(n, 0, -1):
        if arr[i] > arr[i+1]:
            f[i] = max(f[i], f[i+1] + 1)
        elif arr[i] == arr[i+1]:
            f[i] = max(f[i], min(1, f[i-1]))
        else:
            f[i] = max(f[i], 1)
    return sum(f)
if __name__ == "__main__":
    ret = solve()
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    fptr.write(str(ret) + '\n')
    fptr.close()
    