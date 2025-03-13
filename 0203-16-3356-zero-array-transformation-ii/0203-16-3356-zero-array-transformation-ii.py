class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        idx,s,n = 0,0,len(nums)
        frq = [0]*(n+1)
        for i in range(0,n):
            while s+frq[i] < nums[i]:
                if idx == len(queries):
                    return -1
                l,r,val = queries[idx][0],queries[idx][1],queries[idx][2]
                idx+=1
                if r < i:
                    continue
                frq[max(i,l)]+=val
                frq[r+1]-=val
            s+=frq[i]
        return idx
