import sys
import argparse
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def locate(self, head, k):
        n = 1
        while n < k:
            head = head.next
            n = n+1
        return head
    def len(self, head):
        n = 1
        while head:
            head = head.next
            n = n + 1
        return n
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        a= self.locate(head,k)
        le = self.len(head)
        last = le-k+1
        b=self.locate(head,last)
        t = a.val
        a.val = b.val
        b.val = t
        return head

def main():
    pass

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()