class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2,nums1)
        
        m,n = len(nums1),len(nums2)
        total = (n+m)
        l,r = 0, m

        while l <= r:
            md1 = (l+r)//2
            md2 = (total+1)//2 - md1
            print(l,r,md1,md2)

            Aleft = float("-inf") if md1 == 0 else nums1[md1-1]
            Aright = float("inf") if md1 == m else nums1[md1]
            Bleft = float("-inf") if md2 == 0 else nums2[md2-1]
            Bright = float("inf") if md2 == n else nums2[md2]

            if Aleft <= Bright and Bleft <= Aright:
                if total&1:
                    return max(Aleft,Bleft)
                else:
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
            if Aleft > Bright:
                r = md1-1
            else :
                l = md1+1
        return 123