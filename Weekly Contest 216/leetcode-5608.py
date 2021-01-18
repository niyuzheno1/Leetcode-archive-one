import sys
import argparse

def minimumEffort(tasks) -> int:
    ret = 0
    dict1 = {}
    for i in range(0, len(tasks)):
        dict1[i] = tasks[i][1]-tasks[i][0]
    for k,v in sorted(dict1.items(), key=lambda item: item[1]):
        if tasks[k][0] + ret < tasks[k][1]:
            ret = tasks[k][1]
        else:
            ret = tasks[k][0] + ret
    return ret

def main():
    print(minimumEffort( [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()