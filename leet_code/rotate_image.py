"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-22 22:35:29
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

class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        sz = len(matrix)
        arr = [[0 for _ in range(sz)] for _ in range(sz)]
        for i in range(sz):
            for j in range(sz):
                arr[j][sz-i-1] = matrix[i][j]
        for i in range(sz):
            for j in range(sz):
                matrix[i][j] = arr[i][j]
        print(matrix)

def solve():
    matrix = [[1,2,3],[4,5,6],[7,8,9]]
    sol = Solution()
    sol.rotate(matrix)
    pass

if __name__ == "__main__":
    solve()