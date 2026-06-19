"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-19 15:38:26
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
temp  = list(map(int, input().rstrip().split()))
arr = [0 for _ in range(n+10)]
for index in range(n):
    arr[index+1] = temp[index]
inf = int(-2e62)
# ----------------------------------------------------

def solve():
    f = [[inf for _ in range(2)] for _ in range(n+10)]
    f[0][0] = f[0][1] = 0
    for i in range(n):
        for j in range(2):
            if (f[i][j] == inf): continue
            if (j == 0): # case this element was not choosen yet
                # if we decide to take element i+1
                f[i+1][1] = max(f[i+1][1], f[i][j] + arr[i+1])
            # if we decide not to take elemtn i+1 or current element already choosen
            f[i+1][0] = max(f[i+1][0], f[i][j])
    ret = max(f[n][0], f[n][1])
    return ret

if __name__ == "__main__":
    ret = solve()
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    fptr.write(str(ret) + '\n')
    fptr.close()