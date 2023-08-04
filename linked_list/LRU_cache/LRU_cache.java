class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {} # map key to node

        # left=LRU, right=most recent
        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left

    # remove node from list
    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev

    # insert at right
    def insert(self, node):
        # set prev and nxt using rightmost pointer
        prev, nxt = self.right.prev, self.right
        # want prev and nxt to point to node
        prev.next = nxt.prev = node # node is now inserted between them
        node.next, node.prev = nxt, prev


    def get (self, key: int) -> int:
        if key in self.cache:
            # update most recent 
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val # return node pointed to by key
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # update most recent
            self.remove(self.cache[key])
        
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache) > self.cap:
            # remove from list and delete LRU from hashmap
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]
