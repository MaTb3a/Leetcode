class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        cnt = Counter(s)
        n, hp = 0, []
        for c in sorted(cnt, reverse=True):
            heappush(hp, (n, c))
            n += 1
        ans = ""
        while hp:
            if cnt[hp[0][1]] <= repeatLimit:   
                n1, c1 = heappop(hp)
                ans += c1 * cnt[c1]
            else:                              
                n1, c1 = heappop(hp)
                ans += c1 * repeatLimit
                cnt[c1] -= repeatLimit
                if hp:                         
                    n2, c2 = heappop(hp)
                    ans += c2
                    cnt[c2] -= 1
                    if cnt[c2]:
                        heappush(hp, (n2, c2)) 
                    heappush(hp, (n1, c1))     
        return ans