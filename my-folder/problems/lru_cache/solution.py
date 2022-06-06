from collections import OrderedDict

class LRUCache:

    def __init__(self, capacity: int):
        self.od = OrderedDict()
        self.capacity = capacity
        
    def update(self, key: int) -> None:
        a = self.od[key]
        self.od.pop(key)
        self.od[key] = a

    def get(self, key: int) -> int:
        if key in self.od.keys():
            a = self.od[key]
            self.update(key)
            return a
        return -1

    def put(self, key: int, value: int) -> None:
        if(key in self.od.keys()):
            self.od.pop(key)
        self.od[key] = value
        if(len(self.od) > self.capacity):
            self.od.popitem(last = False)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)