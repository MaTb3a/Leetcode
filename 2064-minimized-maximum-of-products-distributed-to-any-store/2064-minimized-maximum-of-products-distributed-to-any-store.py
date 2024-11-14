class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        l,r,cur,md = 1,100000,-1,0
        while l <=r:
            md = (l+r)//2
            cnt = 0
            for x in quantities:
                cnt+=math.ceil(x/md)
            if cnt <= n:
                cur= md
                r = md -1
            else :
                l = md+1
        return cur
            