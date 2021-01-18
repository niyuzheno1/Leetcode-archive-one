import sys
import argparse

class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        f = {}
        n = len(deliciousness)
        ans = 0
        for i in range(0,n):
            for j in range(0, 41):
                u = 1<<j
                if u-deliciousness[i] in f:
                    ans += f[u-deliciousness[i]]
                    ans %= 1000000007
            f[deliciousness[i]] = 1 if deliciousness[i] not in f else f[deliciousness[i]]  + 1 
        return ans

def main():
    pass

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()