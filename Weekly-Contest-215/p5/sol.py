import sys
import argparse

f = {}

def decode(x, y, n):
    anx = []
    for i in range(0,n):
        anx.append((x & 3))
        x >>= 2
    ret = [[],[]]
    for i in range(0,n):
        ret[0].append(0)
    for i in range(0,n):
        ret[1].append(0)
    ty = y
    tx = 1
    for i in range(0, len(anx)):
        ret[tx][ty] = anx[i]
        if ty - 1 < 0:
            ty = n - 1
            tx = tx -1
        else:
            ty = ty - 1
            
    if y == n-1:
        for j in range(0,n):
            ret[0][j] = ret[1][j]
            ret[1][j] = 0
    return ret

def finds(x,y, cell):
    if y < 0:
        return 0
    if cell[x][y] == 1:
        return -30
    elif cell[x][y] == 2:
        return 20
    return 0

def finds2(x,y,cell):
    cnt = 0
    if y > 0:
        if cell[x][y-1] > 0:
            cnt = cnt + 1
    if cell[x-1][y] > 0:
        cnt = cnt + 1
    return cnt 

def compute(x, r):
    ret = finds2(1,r,x)*finds(1,r,x)
    ret += finds(0,r,x)
    ret += finds(1,r-1,x)
    return ret

def encoder(x, y, n):
    ret = 0
    for i in range(0,n):
        ret <<= 2
        ret |= x[0][i]
    for i in range(0,y+1):
        ret <<= 2
        ret |= x[1][i]
    mask = (1<<(2*n)) -1
    return (ret & mask)
        

def getMaxGridHappiness2( m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
    for i in range(-1, m):
        for j in range(0, n):
            for k in range(0,introvertsCount+2):
                for l in range(0,extrovertsCount + 2):
                    f[(i,j,k,l)] = {}
    f[(-1,n-1, introvertsCount, extrovertsCount)][0] = 0
    for i in range(0,m):
        for j in range(0,n):
            oi = i-1 if j==0 else i
            oj = n-1 if j == 0 else j-1
            for k in range(0,introvertsCount+1):
                for l in range(0,extrovertsCount + 1):
                    for x in f[(oi,oj,k,l)]:
                        f[(i,j,k,l)][x] = f[(oi,oj,k,l)][x]
            for k in range(0,introvertsCount+1):
                for l in range(0,extrovertsCount + 1):
                    for x in f[(oi,oj,k+1,l)]:
                        retx = decode(x, oj, n)
                        retx[1][j] = 1
                        rety = compute(retx,j)
                        rety += 120
                        rety += f[(oi,oj,k+1,l)][x]
                        xx = encoder(retx, j, n)
                        if xx not in f[(i,j,k,l)]:
                            f[(i,j,k,l)][xx] = rety
                        else:
                            f[(i,j,k,l)][xx] = max(f[(i,j,k,l)][xx],rety)
                    for x in f[(oi,oj,k,l+1)]:
                        retx = decode(x, oj, n)
                        retx[1][j] = 2
                        rety = compute(retx,j)
                        rety += 40
                        rety += f[(oi,oj,k,l+1)][x]
                        xx = encoder(retx, j, n)
                        if xx not in f[(i,j,k,l)]:
                            f[(i,j,k,l)][xx] = rety
                        else:
                            f[(i,j,k,l)][xx] = max(f[(i,j,k,l)][xx],rety)         
    ans = None
    for k in range(0,introvertsCount+1):
            for l in range(0,extrovertsCount + 1):
                for x in f[(m-1,n-1,k,l)]:
                    if ans is None:
                        ans = f[(m-1,n-1,k,l)][x]
                    else:
                        ans = max(ans, f[(m-1,n-1,k,l)][x])
    return ans
from functools import lru_cache 

import math
def getMaxGridHappiness( m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
    @lru_cache(None)
    def searchx(last, x, y, numin, numex):
        if numin < 0 or numex < 0:
            return -math.inf
        if x < 0:
            return 0
        
        nx = x if y > 0 else x - 1
        ny = y-1 if y > 0 else  n-1
        ans = searchx(last[1:] + "0" , nx , ny , numin , numex)
        in_neigbors = 0
        out_neighbors = 0
    
        if last[0] == '1':
            in_neigbors = in_neigbors + 1
        if last[0] == '2':
            out_neighbors = out_neighbors + 1
        if y != n-1:
            if last[-1] == '1':
                in_neigbors = in_neigbors + 1
            if last[-1] == '2':
                out_neighbors = out_neighbors + 1
        ans2 = searchx(last[1:] + '1' , nx , ny , numin-1, numex) + 120 - 30 * (in_neigbors + out_neighbors)  - 30 * in_neigbors + 20 * out_neighbors
        ans3 = searchx(last[1:] + '2' , nx , ny , numin, numex-1) + 40  + 20 * (in_neigbors + out_neighbors)  - 30 * in_neigbors + 20 * out_neighbors
        return max(ans2, ans3, ans)

    return searchx( "0" * n, m-1, n-1, introvertsCount, extrovertsCount)

def main():
    print(getMaxGridHappiness(3,1, 2 , 1))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()