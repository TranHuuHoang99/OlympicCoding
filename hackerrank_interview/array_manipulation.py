"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-19 11:49:26
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
multi_val = input().rstrip().split()
n = int(multi_val[0])
q = int(multi_val[1])
# ----------------------------------------------------

def solve():
    prefix = [0 for _ in range(n+2)]
    for _ in range(q):
        a, b, val = map(int, input().rstrip().split())
        prefix[a] += val
        prefix[b+1] -= val
    ret = 0
    sum = 0
    for i in range(1, n+1):
        sum += prefix[i]
        ret = max(ret, sum)
    return ret

if __name__ == "__main__":    
    ret = solve()
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    fptr.write(str(ret) + '\n')
    fptr.close()
