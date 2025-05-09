class Solution(object):
    def countBalancedPermutations(self, num):
        mod = 10**9+7
        n = len(num)
        total = sum(int(c) for c in num)
        if total % 2: return 0
        fact = [1]*(n+1)
        inv = [1]*(n+1)
        invFact = [1]*(n+1)
        for i in range(1,n+1): fact[i] = fact[i-1]*i % mod
        for i in range(2,n+1): inv[i] = mod - (mod//i)*inv[mod%i] % mod
        for i in range(1,n+1): invFact[i] = invFact[i-1]*inv[i] % mod
        halfSum = total//2
        halfLen = n//2
        dp = [[0]*(halfLen+1) for _ in range(halfSum+1)]
        dp[0][0] = 1
        digits = [0]*10
        for c in num:
            d = int(c)
            digits[d] += 1
            for i in range(halfSum, d-1, -1):
                for j in range(halfLen, 0, -1):
                    dp[i][j] = (dp[i][j] + dp[i-d][j-1]) % mod
        res = dp[halfSum][halfLen]
        res = res * fact[halfLen] % mod * fact[n-halfLen] % mod
        for cnt in digits: res = res * invFact[cnt] % mod
        return res