"""
**************************************************************************
    author     : hoangprodn
    email      : thhoang08091999@gmail.com
    local time : 2026-06-23 17:18:28
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

class Node:
    def __init__(self, key: int, data: int):
        self.key: int = key
        self.data: int = data
        self.frequent = 1
        self.prev: Node = None
        self.next: Node = None

class DoublyLinkedList:
    def __init__(self):
        self.head: Node = Node(0,0)
        self.tail: Node = Node(0,0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.sz_: int = 0
    def isEmpty(self) -> bool:
        return self.sz_ == 0
    # push to the top of the list
    def push(self, node: Node) -> None:
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node
        self.sz_ += 1
    # pop the end of the list
    def remove(self, node: Node) -> None:
        prev_node: Node = node.prev
        next_node: Node = node.next
        prev_node.next = next_node
        next_node.prev = prev_node
        self.sz_ -= 1
    def pop(self) -> Node:
        if self.isEmpty() is True:
            print("current list is empty")
            return None
        lfu_node = self.tail.prev
        self.remove(lfu_node)
        return lfu_node

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity_: int = capacity
        self.key_map_: dict[int, Node] = {}
        self.fre_map_: dict[int, DoublyLinkedList] = {}
        self.min_fre_: int = 1
    def __update_frequency(self, node: Node) -> None:
        cur_freq: int = node.frequent
        new_freq: int = cur_freq + 1
        cur_freq_list: DoublyLinkedList = self.fre_map_[cur_freq]
        cur_freq_list.remove(node)
        node.frequent = new_freq
        if cur_freq_list.isEmpty() is True and cur_freq == self.min_fre_:
            self.min_fre_ += 1
        if new_freq not in self.fre_map_:
            self.fre_map_[new_freq] = DoublyLinkedList()
        self.fre_map_[new_freq].push(node)
    def put(self, key: int, data: int) -> None:
        if self.capacity_ <= 0:
            print("capacity is 0")
            return
        # case 1 : current key already existed
        if key in self.key_map_:
            node: Node = self.key_map_[key]
            node.data = data
            self.__update_frequency(node)
            return
        # case 2: create new key and check whether current capacity
        # is available or not
        if len(self.key_map_) >= self.capacity_:
            print(f"current capacity is full: {len(self.key_map_)}/{self.capacity_}")
            # pop the lease use node in the smallest frequency Doublylinkedlist
            min_freq_list: DoublyLinkedList = self.fre_map_[self.min_fre_]
            evicted_node: Node = min_freq_list.pop()
            if evicted_node is not None:
                del self.key_map_[evicted_node.key]
        # case 3: create new node and push to the list with frequence is 1
        new_node: Node = Node(key, data)
        self.key_map_[key] = new_node
        # reset to 1
        self.min_fre_ = 1
        if 1 not in self.fre_map_:
            self.fre_map_[1] = DoublyLinkedList()
        self.fre_map_[1].push(new_node)
    def get(self, key: int) -> int:
        if key not in self.key_map_:
            return -1
        node: Node = self.key_map_[key]
        # this node has just been access, we need to update frequence
        self.__update_frequency(node)
        return node.data
    def display(self) -> None:
        for freq, dlist in sorted(self.fre_map_.items()):
            if dlist.isEmpty() is True:
                continue
            cur_node: Node = dlist.head.next
            elements: list[str] = []
            while cur_node != dlist.tail:
                elements.append(f"[{cur_node.key}:{cur_node.data}]")
                cur_node = cur_node.next
            print(f"frequency {freq} : " + " -> ".join(elements))

def solve():
    cache: LFUCache = LFUCache(capacity=2)
    cache.put(1, 1999)
    cache.put(2, 1968)
    cache.display()
    print(cache.get(1))
    cache.display()
    cache.put(3, 2027)
    cache.display()

if __name__ == "__main__":
    solve()