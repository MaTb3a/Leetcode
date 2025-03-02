class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        i,j,n,m = 0,0,len(nums1),len(nums2)
        v = []
        while i < n or j < m :
            id1 = nums1[i][0] if i < n else float('inf')
            id2 = nums2[j][0] if j < m else float('inf')
            if id1 < id2 :
                v.append(nums1[i])
                i+=1
            elif id2 < id1:
                v.append(nums2[j])
                j+=1
            else:
                v.append((id1,nums1[i][1]+nums2[j][1]))
                i+=1
                j+=1
        return v
                