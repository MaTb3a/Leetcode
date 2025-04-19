class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        def solve(nums,sum):
            i,j = 0 , len(nums)-1
            cnt = 0
            while i < j :
                if nums[i] + nums[j] <= sum:
                    cnt+=j-i
                    i+=1
                else :
                    j-=1
            return cnt
        nums.sort()
        return solve(nums,upper) - solve(nums,lower-1)