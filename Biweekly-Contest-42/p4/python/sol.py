from collections import deque
class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        mq = deque([])
        n = len(nums)
        szeros = [0]*n
        sones = [0]*n
        for i in range(0, n):
            if i >= 1:
                szeros[i] = szeros[i-1]
                sones[i] = sones[i-1]
            if nums[i] == 0:
               szeros[i] = szeros[i] + 1
            else:
                sones[i] = sones[i] + 1
        l = 0
        for i in range(0,n):
            if nums[i] == 1:
                mq.append(i)
            if len(mq) >= k:
                l = i
                break
        ans = szeros[mq[-1]]-szeros[mq[0]]
        for i in range(l+1,n):
            if nums[i] == 1:
                while len(mq) == k:
                    mq.popleft()
                mq.append(i)
                ans = min(szeros[mq[-1]]-szeros[mq[0]], ans)
        return ans

