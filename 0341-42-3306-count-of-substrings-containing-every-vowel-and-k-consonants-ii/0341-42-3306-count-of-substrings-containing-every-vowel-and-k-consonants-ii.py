class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        def solve(s: str, target_k: int) -> int:
            mp = [0] * 26
            cons = 0
            ans = 0
            l = 0
            n = len(s)
            for r in range(n):
                c = s[r]
                if self.isVowel(c):
                    mp[ord(c) - ord('a')] += 1
                else:
                    cons += 1
                while l <= r and self.check(mp) and cons >= target_k:
                    ans += n - r
                    # Move left pointer
                    left_c = s[l]
                    if self.isVowel(left_c):
                        mp[ord(left_c) - ord('a')] -= 1
                    else:
                        cons -= 1
                    l += 1
            return ans
        
        return solve(word, k) - solve(word, k + 1)
    
    def isVowel(self, c: str) -> bool:
        return c in {'a', 'e', 'i', 'o', 'u'}
    
    def check(self, mp) -> bool:
        return mp[0] > 0 and mp[4] > 0 and mp[8] > 0 and mp[14] > 0 and mp[20] > 0