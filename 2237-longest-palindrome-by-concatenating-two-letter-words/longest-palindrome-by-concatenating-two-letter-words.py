class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        mp = {}
        ans = 0
        for s in words:
            if s[::-1] in mp:
                mp[s[::-1]]-=1
                if mp[s[::-1]] == 0:
                    del mp[s[::-1]]
                ans+=4
            else :
                if s in mp:
                    mp[s]+=1
                else :
                    mp[s] =1

        for s in mp.keys():
            if s[0] == s[1]:
                return ans+2
        return ans