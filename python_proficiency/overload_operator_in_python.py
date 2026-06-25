"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-25 23:41:24
**************************************************************************
"""
from collections import deque, Counter, defaultdict
import heapq
import bisect
import math
import sys
import os
from functools import cmp_to_key
# ----------------------------------------------------
input = sys.stdin.readline
# ----------------------------------------------------

class NodeMin:
    def __init__(self, name: str, prior: int, data: int):
        self.name = name
        self.prior = prior
        self.data = data
    def __lt__(self, other: NodeMin):
        if self.prior == other.prior:
            return self.data < other.data
        return self.prior < other.prior

def solve():
    min_heap: list[NodeMin] = []
    heapq.heappush(min_heap, NodeMin("hoang", 1999, 123))
    heapq.heappush(min_heap, NodeMin("other", 1, 12))
    heapq.heappush(min_heap, NodeMin("nhan", 1, 1))
    while min_heap:
        top: NodeMin = heapq.heappop(min_heap)
        print(f"name : {top.name}, priority: {top.prior}, data: {top.data}")

if __name__ == "__main__":
    solve()