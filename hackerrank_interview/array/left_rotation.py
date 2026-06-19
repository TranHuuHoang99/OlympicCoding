#!/bin/python3
from collections import deque
import math
import os
import random
import re
import sys

def rotLeft(a, d):
    arr = deque()
    for e in a:
        arr.append(e)
    for _ in range(d):
        if arr:
            val = arr[0]
            arr.popleft()
            arr.append(val)
    return arr

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    first_multiple_input = input().rstrip().split()
    n = int(first_multiple_input[0])
    d = int(first_multiple_input[1])
    a = list(map(int, input().rstrip().split()))
    result = rotLeft(a, d)
    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')
    fptr.close()
