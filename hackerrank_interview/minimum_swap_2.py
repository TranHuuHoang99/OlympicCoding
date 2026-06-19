"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-19 10:29:47
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
temp = list(map(int, input().rstrip().split()))
# ----------------------------------------------------

def solve():
    arr = [0 for _ in range(n+1)]
    visited = [False for _ in range(n+1)]
    for i in range(1, n+1):
        arr[i] = temp[i-1]
    cnt = 0
    for i in range(1, n+1):
        if (arr[i] == i or visited[i]): continue
        len = 0
        cur = i
        while not visited[cur]:
            visited[cur] = True
            cur = arr[cur]
            len += 1
        cnt += max(0, len-1)
    return cnt

if __name__ == "__main__":
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    ret = solve()
    fptr.write(str(ret) + '\n')
    fptr.close()
