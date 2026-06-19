"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-19 15:57:40
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
# ----------------------------------------------------

def check(char):
    if 'a' <= char and char <= 'z':
        return 0
    return 1
def capitalize(a):
    temp = ord(a) - ord('a')
    return chr(ord('A')+temp)
def solve(a: str, b: str):
    n = len(a)
    m = len(b)
    f = [[False for _ in range(m+10)] for _ in range(n+10)]
    # two string in the beginning are the
    f[0][0] = True
    # case string b is empty
    for i in range(1, n+1):
        if check(a[i-1]) == 0: # if string a letter is lower case, we could remove it out of the string
            f[i][0] = f[i-1][0]
    for i in range(1, n+1):
        for j in range(1, m+1):
            isALowerCase = (check(a[i-1]) == 0)
            if isALowerCase:
                # delete this letter in string a
                remove_letter = f[i-1][j]
                # capitalize it to be upper case
                capLetter = False
                if capitalize(a[i-1]) == b[j-1]:
                    capLetter = f[i-1][j-1]
                f[i][j] = remove_letter or capLetter
            else:
                if a[i-1] == b[j-1]:
                    f[i][j] = f[i-1][j-1]
                else:
                    f[i][j] = False
    if (f[n][m] == True):
        return "YES"
    return "NO"

if __name__ == "__main__":
    q = int(input().rstrip())
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    for _ in range(q):
        a = input().rstrip()
        b = input().rstrip()
        ret = solve(a, b)
        print(ret)
        fptr.write(ret + '\n')
    fptr.close()
