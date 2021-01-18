class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        if len(nums1) == 0 and len(nums2) == 0:
            return 0
        if len(nums2) == 0:
            u = len(nums1)-1
            lx = nums1[u >> 1] + (nums1[(u >> 1)+1] if (u+1) % 2 == 0 else nums1[u>>1])
            return lx/2
        if len(nums1) == 0:
            u = len(nums2)-1
            lx = nums2[u >> 1] + (nums2[(u >> 1)+1] if (u+1) % 2 == 0 else nums2[u>>1])
            return lx/2
        l = 0
        r = len(nums1)
        le = (len(nums1) + len(nums2)) >> 1
        l1 = len(nums1)
        l2 = len(nums2)
        while l < r:
            mid = (l+r)>>1
            midy = le - mid
            if mid > 0 and midy < l2 and midy >= 0 and nums1[mid-1] > nums2[midy]:
                r = mid-1
                continue
            if midy > 0 and mid < l1 and midy - 1 < l2 and nums2[midy-1] > nums1[mid]:
                l = mid + 1
                continue
            if midy - 1 >= l2:
                l = mid + 1
                continue
            if midy < 0:
                r = mid - 1
                continue
            l = mid
            r = mid
        if (l1+l2) % 2 == 1:
            midy = le - l - 1
            l = l - 1
            le1 = nums1[l+1] if l + 1 < l1 else 10e+9
            le2 = nums2[midy+1] if midy + 1 < l2 else 10e+9
            return min(le1, le2)
        else:
            midy = le - l - 1
            l = l - 1
            le1 = max( nums1[l] if l >= 0 else 0, nums2[midy] if midy >= 0 else 0)
            le2 = min(nums1[l+1] if l +1 < l1 else 10e+9, nums2[midy+1] if midy+1 < l2 else 10e+9)
            return (le1+ le2)/2



u = Solution()
u.findMedianSortedArrays([1,2,3,4,5,7,8,9,10], [6])