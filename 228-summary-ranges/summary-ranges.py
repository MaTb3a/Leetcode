class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        i,j,n = 0,1,len(nums)
        ans = []
        if not nums:
            return ans
            
        while j < n:
            if nums[j] == nums[j-1]+1:
                j+=1
            else:
                # push
                a = nums[i]
                b = nums[j-1]
                if a == b:
                    ans.append(str(a))
                else:
                    ans.append(str(a)+"->"+str(b))
                i = j
                j+=1
        
        a = nums[i]
        b = nums[j-1]
        if a == b:
            ans.append(str(a))
        else:
            ans.append(f"{a}->{b}")
        return ans
        


