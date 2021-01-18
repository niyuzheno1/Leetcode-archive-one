class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        begins = head
        pres = None
        while True:
            cnt = 0
            ends = begins
            while cnt < k and ends.next is not None:
                ends = ends.next
                cnt = cnt + 1
            if cnt < k-1:
                break
            
            if cnt == k-1:
                fends = ends = None
            else:
                fends = ends
            cnt = 0
            while cnt < k-1 and fends is not None:
                fends = fends.next
                cnt = cnt + 1
            fu = None
            for i in range(0,k):
                ne = begins 
                for j in range(0,k-i-1):
                    ne = ne.next
                if fu is not None:
                    fu.next = ne
                if pres is None:
                    pres = ne
                fu = ne
            fu.next = fends if fends is not None else ends
            if fends is None:
                break
            begins = ends
        if pres is None:
            return head
        return pres


a = Solution()
def tolistnode(x):
    n = len(x)
    pre = None
    for i in range(n):
        pre = ListNode(x[n-i-1],pre)
    return pre

nodes = tolistnode([1,2,3,4,5])
def printlistnode(x):
    l = []
    while x is not None:
        l.append(x.val)
        x = x.next
    print(l)
    return l

printlistnode(a.reverseKGroup(nodes,1))