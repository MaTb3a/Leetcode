class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        def ok(md):
            cnt = 0
            for x in candies:
                cnt+=x//md
            return cnt>=k
    
        st,ed,cur,md = 1,max(candies),0,0
        while st <=ed:
            md = (st+ed)//2
            if ok(md):
                cur = md
                st = md+1
            else:
                ed = md-1
        return cur