class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        def solve(nums,md):
            moves=0
            for x in nums:
                moves+=abs(x-md);
            return moves   
        l,r,ans=-1000000000,1000000000,99999999999999
        while r-l > 3:
            md1 = l+(r-l)//3
            md2 = l+2*( (r-l)//3)
            
            if(solve(nums,md1)<solve(nums,md2)):
                r=md2
            else :
                l=md1
        for i in range(l,r):
            tmp = solve(nums,i)
            if(tmp<ans):
                ans=tmp
                md=i
        
        return ans