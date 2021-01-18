class FrontMiddleBackQueue:

    def __init__(self):
        self.que = []
    def isempty(self):
        if len(self.que) == 0:
            return True
        else:
            return False
    def pushFront(self, val: int) -> None:
        self.que = [val] + self.que

    def pushMiddle(self, val: int) -> None:
        l = len(self.que)
        pos = l//2
        head = self.que[:pos]
        tail = self.que[pos:]
        self.que = head + [val] + tail
        


    def pushBack(self, val: int) -> None:
        self.que = self.que + [val]

    def popFront(self) -> int:
        if self.isempty():
            return -1
        ret = self.que[0]
        self.que = self.que[1:]
        return ret

    def popMiddle(self) -> int:
        if self.isempty():
            return -1
        l = len(self.que)
        l = l-1
        pos = l//2
        val = self.que[pos]
        head = self.que[:pos]
        tail = self.que[pos+1:]
        self.que = head + tail
        return val
        
    def popBack(self) -> int:
        if self.isempty():
            return -1
        ret = self.que[-1]
        self.que = self.que[:-1]
        return ret


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()
q = FrontMiddleBackQueue()
q.pushFront(1);   
print(q.que)
q.pushBack(2);
print(q.que)    
q.pushMiddle(3);  # [1, 3, 2]
print(q.que)
q.pushMiddle(4);  # [1, 4, 3, 2]
print(q.que)
ret = q.popFront();     # return 1 -> [4, 3, 2]
print(q.que)
print(ret)
ret = q.popMiddle();    # return 3 -> [4, 2]
print(q.que)
print(ret)
ret =q.popMiddle();    # return 4 -> [2]
print(q.que)
print(ret)
ret = q.popBack();      # return 2 -> []
print(q.que)
print(ret)
ret = q.popFront();     # return -1 -> [] (The queue is empty)
print(q.que)
print(ret)