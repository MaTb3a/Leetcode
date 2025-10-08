class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort(reverse=True)
        ans = []
        for x in (spells):
            l,r,cur = 0,len(potions)-1,-1
            while l <= r:
                md = (l+r)//2
                if potions[md] * x >= success:
                    cur = md
                    l = md+1
                else:
                    r = md-1
            ans.append(cur+1)
        return ans