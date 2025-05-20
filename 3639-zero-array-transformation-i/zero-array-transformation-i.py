class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        idx,s,n = 0,0,len(nums)
        frq = [0]*(n+1)
        for i in range(0,n):
            while s+frq[i] < nums[i]:
                if idx == len(queries):
                    return False
                l,r,val = queries[idx][0],queries[idx][1],1
                idx+=1
                if r < i:
                    continue
                frq[max(i,l)]+=val
                frq[r+1]-=val
            s+=frq[i]
        return True