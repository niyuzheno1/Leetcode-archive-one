import sys
import argparse

class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        n = len(rectangles)
        b = {}
        a = []
        for i in range(0,n):
            a.append(min(rectangles[i][0],rectangles[i][1]))
        a = sorted(a,reverse=True)
        for i in range(0,n):
            b[a[i]] = 0
        for i in range(0,n):
            b[a[i]] = b[a[i]]+1
        return b[a[0]]

def main():
    pass

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()