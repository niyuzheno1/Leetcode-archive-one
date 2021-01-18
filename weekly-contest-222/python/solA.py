import sys
import argparse

class Solution:
    def maximumUnits(self, boxTypes, truckSize: int) -> int:
        boxTypes = sorted(boxTypes, key=lambda x: x[1], reverse=True)
        n = len(boxTypes)
        ans = 0
        ts = truckSize
        for i in range(0, n):
            ans += min(boxTypes[i][0],ts) * boxTypes[i][1]
            ts -= min(boxTypes[i][0],ts)
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