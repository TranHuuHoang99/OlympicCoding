"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-22 11:26:35
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
# decimal max is 3e5, and 2^19 is over 3e5 so we only need
# 19 power of two to perform, and maximum value is 3e5
f = [[0 for _ in range(int(3e5+1))] for _ in range(22)]
prefix = [0 for _ in range(int(3e5+1))]
# ----------------------------------------------------
def pre_compute():
    # base case: value from 0 -> 9 only could be perform once
    for digit in range(10):
        f[0][digit] = 1
    for i in range(20):
        weight = int(1 << (i+1))
        for val in range(int(3e5+1)):
            for digit in range(10):
                if digit * weight + val > 3e5:
                    break
                f[i+1][digit*weight+val] += f[i][val]
    # 0 has one way to perform
    prefix[0] = 1
    for val in range(1, int(3e5+1)):
        prefix[val] = prefix[val-1] + f[19][val]
        
def solve():
    x = int(input().rstrip())
    if x == 1:
        return "0"
    val = bisect.bisect_left(prefix, x, 0, int(3e5))
    order = x - prefix[val-1]
    ret = ""
    started = False
    for i in range(19, -1, -1):
        weight = (1 << i)
        for j in range(10):
            if val < weight * j:
                continue
            rem_val = val - weight * j
            cnt = f[i-1][rem_val] if i > 0 else (1 if rem_val == 0 else 0)
            if order <= cnt:
                if j > 0 or started or i == 0:
                    ret += str(j)
                    started = True
                val = rem_val
                break
            else:
                order -= cnt
    return ret

if __name__ == "__main__":
    pre_compute()
    q = int(input().rstrip())
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    for _ in range(q):
        result = solve()
        fptr.write(result + '\n')
    fptr.close()

