"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-22 19:08:27
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
INF = int(2**62)
N = int(3e3+10)
adj = [[] for _ in range(N)]
visited = [False for _ in range(N)]
connect = [0 for _ in range(N)]
# ----------------------------------------------------
def reset():
    global visited
    for i in range(N):
        adj[i].clear()
        visited[i] = False
        connect[i] = 0
def dfs(u: int):
    global visited, connect
    for v in adj[u]:
        if not visited[v]:
            visited[v] = True
            if connect[v] == 0 or dfs(connect[v]) is True:
                connect[v] = u
                return True
    return False
def solve():
    global cnt, visited
    n, k = map(int, input().rstrip().split())
    arr = [0] + list(map(int, input().rstrip().split()))
    for u in range(1, n+1):
        for v in range (u+1, n+1):
            diff = abs(arr[u] - arr[v])
            if diff >= k:
                adj[u].append(v)
    cnt = 0
    for u in range(1, n+1):
        for i in range(1, n+1):
            visited[i] = False
        isValid = dfs(u)
        if isValid is True:
            cnt += 1
    return n - cnt
if __name__ == "__main__":
    t = int(input().rstrip())
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    for _ in range(t):
        reset()
        ret = solve()
        # print(ret)
        fptr.write(str(ret)+'\n')
    fptr.close()
