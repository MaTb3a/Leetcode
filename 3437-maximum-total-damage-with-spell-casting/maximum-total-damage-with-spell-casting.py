class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        mp = defaultdict(int)
        for x in power:
            mp[x]+=1
        lst = []
        for k,v in mp.items():
            lst.append([k,v*k])
        lst.sort()
        n = len(lst)

        @lru_cache()
        def solve(i):
            if i >= n:
                return 0
            ret = solve(i+1)
            j = i+1
            x = lst[i][0]
            while j < n and lst[j][0] <= x+2:
                j+=1
            ret=max(ret,solve(j)+lst[i][1])
            return ret
            
        return solve(0)


