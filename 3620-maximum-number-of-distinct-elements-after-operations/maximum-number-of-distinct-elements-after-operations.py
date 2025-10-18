class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        mp = {}
        cnt = 0
        for x in nums:
            l,r,cur=x-k,x+k,-3000000000
            while l <=r :
                md = (l+r)//2
                if md not in mp:
                    cur = md
                    r = md-1
                else:
                    l = md+1
            if cur != -3000000000:
                mp[cur] = True
        return len(mp)

      