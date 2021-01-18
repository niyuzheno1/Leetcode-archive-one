# your code goes here
from collections import deque
def boxDelivering(boxes, portsCount, maxBoxes, maxWeight):
     n = len(boxes)
     mq = deque([(0,0)])
     sw = [0] * (n+1)
     dp = [0] * (n+1)
     def g(i):
         if i == n:
             return 0
         j = i-1
         return (1 if boxes[j][0] != boxes[j+1][0] else 2)
     def insertmq(x):
         while len(mq) > 0 and mq[-1][0] > x[0]:
             mq.pop()
         mq.append(x)
     def update(i):
         while len(mq) > 0 and ( i - mq[0][1] > maxBoxes or sw[i] - sw[mq[0][1]] > maxWeight):
             mq.popleft()
         return mq[0]
     for i in range(0,n):
         sw[i+1] = (sw[i] if i >= 1 else 0) + boxes[i][1]
     for i in range(1,n+1):
         res = update(i)
         dp[i] = res[0]
         insertmq((dp[i]+g(i), i))
     invar = 2
     for i in range(0,n-1):
          if boxes[i][0] != boxes[i+1][0]:
               invar = invar + 1
     return dp[n] + invar
 
 

print(boxDelivering( [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]], 3, 6, 7))