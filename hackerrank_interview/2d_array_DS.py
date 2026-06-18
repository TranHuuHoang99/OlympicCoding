"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-18 21:41:26
**************************************************************************
"""
from collections import deque, Counter, defaultdict
import heapq
import bisect
import math
import os
import sys
from functools import cmp_to_key
# set recursion limit
sys.setrecursionlimit(int(2e5))
# handle input
# ----------------------------------------------------
input = sys.stdin.readline
arr = []
for _ in range(6):
    arr.append(list(map(int, input().rstrip().split())))
# ----------------------------------------------------

def solve():
    ret = int(-2e9)
    for row in range(4):
        for col in range(4):
            cnt = 0
            sum = 0
            for i in range(row, row+3, 1):
                for j in range(col, col+3, 1):
                   cnt += 1
                   if (cnt == 4 or cnt == 6): continue
                   sum += arr[i][j]
            ret = max(ret, sum)
    return ret

if __name__ == "__main__":
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    ret = solve()
    fptr.write(str(ret) + '\n')
    fptr.close()