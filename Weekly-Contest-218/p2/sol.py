
def maxOperations( nums: List[int], k: int) -> int:
        a = sorted(nums)
        l = 0
        r = len(a)-1
        while(r > 0 and a[r]+a[l] > k):
            r = r-1
        return 3
    
print(maxOperations([3,1,3,4,3], 3))