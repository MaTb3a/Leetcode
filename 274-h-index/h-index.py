class Solution:
    def hIndex(self, citations: List[int]) -> int:
        l ,r,cur = 0,1000,-1
        while l <=r :
            md = (l+r)//2
            cnt = 0
            for x in citations:
                cnt+= x>=md
            if cnt >=md:
                cur = md
                l = md+1
            else:
                r = md -1
        return cur 