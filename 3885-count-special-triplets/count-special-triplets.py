class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        
        ans = 0
        L = defaultdict(int)
        R = Counter(nums)

        for x in nums:
            R[x]-=1
            v = x*2
            if v in R and v in L:
                ans+=L[v]*R[v]
                ans%=1000000007
            L[x]+=1
        return ans