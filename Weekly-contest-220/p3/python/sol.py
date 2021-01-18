from collections import deque
def maxResult( nums, k):
    q = deque([(nums[0],0)])
    n = len(nums)
    def update(i):
        while len(q) > 0 and i-q[0][1] > k:
            q.popleft()
    def insert(x):
        while len(q) > 0 and q[-1][0] <= x[0]:
            q.pop()
        q.append(x)
    dp = [0]*(n+1)
    for i in range(n):
        update(i)
        dp[i] = q[0][0]+nums[i]
        insert((dp[i],i))
    return dp[n-1]