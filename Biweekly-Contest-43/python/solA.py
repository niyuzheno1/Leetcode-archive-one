import sys
import argparse
class Solution(object):
    def totalMoney(self, n):
        """
        :type n: int
        :rtype: int
        """
        

def main():
    pass

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()