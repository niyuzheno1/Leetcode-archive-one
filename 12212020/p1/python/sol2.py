class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
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
        l = [0,0]
        r = [len(nums1)-1,len(nums2)-1]
        q = (len(nums1)-1,len(nums2)-1)
        tot = len(nums1)+len(nums2)
        total = (len(nums1)+len(nums2))//2
        while l[0]  < r[0] and l[1] < r[1]:
        	mid = ((l[0]+r[0])>>1, (l[1]+r[1])>>1)
        	if nums1[mid[0]] < nums2[mid[1]]:
        		if q[1]-(mid[1]-1) + q[0]-(mid[0]-1) > total+1:
        			l[0] = mid[0] + 1
        		elif q[1]-(mid[1]-1) + q[0]-(mid[0]-1) >= total:
        			l[0] = mid[0]
        		if mid[1] + 1 + mid[0] + 1 > total + 1:
        			r[1] = mid[1] - 1
        		elif mid[1] + 1 + mid[0] + 1 >= total:
        			r[1] = mid[1]
        	else:
        		if q[1]-(mid[1]-1) + q[0]-(mid[0]-1) > total+1:
        			l[1] = mid[1] + 1
        		elif q[1]-(mid[1]-1) + q[0]-(mid[0]-1) >= total:
        			l[1] = mid[1]
        		if mid[1] + 1 + mid[0] + 1 > total + 1:
        			r[0] = mid[0] - 1
        		elif mid[1] + 1 + mid[0] + 1 >= total:
        			r[0] = mid[0]
        if tot % 2 == 1:
            mid = ((l[0]+r[0])>>1, (l[1]+r[1])>>1)
            if nums1[mid[0]] < nums2[mid[1]]:
                if q[1]-(mid[1]-1) + q[0]-(mid[0]-1) == total+1:
                    print(nums1[mid[0]])
                if mid[1] + 1 + mid[0] + 1 == total + 1:
                    print(nums2[mid[1]])
            elif nums1[mid[0]] == nums2[mid[1]]:
                print(nums2[mid[1]])
            else:
                if q[1]-(mid[1]-1) + q[0]-(mid[0]-1) == total+1:
                    print(nums2[mid[1]])
                if mid[1] + 1 + mid[0] + 1 == total + 1:
                    print(nums1[mid[0]])
                
        else:
            return (nums1[l[0]]+nums2[l[1]])/ 2

u = Solution()
u.findMedianSortedArrays( [3], [-1,-2])