"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-25 16:28:03
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
    n, k = map(int, input().rstrip().split())
    sample = input().rstrip()
    pi: list[int] = [0] * 60
    index = 0
    sample = " " + sample
    for i in range(2, n+1):
        while index > 0 and sample[index+1] != sample[i]:
            index = pi[index]
        if sample[index+1] == sample[i]:
            index += 1
        pi[i] = index
    suffix = sample[index+1:]
    ret = ""
    for i in range(1, n+1):
        ret += sample[i]
    for i in range(1, k):
        ret += suffix
    print(ret)
        
if __name__ == "__main__":
    solve()