class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        MOD = 10**9 + 7
        ans = maxValue
        frq = {num: 1 for num in range(1, maxValue + 1)}
        
        for sz in range(1, n): 
            frq2 = Counter()
            for v in frq: 
                for mul in range(2, maxValue // v + 1): 
                    combinations = comb(n - 1, sz) # built in functoin to choose k from n items
                    ans += combinations * frq[v]
                    frq2[mul * v] += frq[v]
            frq = frq2
            ans %= MOD
        
        return ans 