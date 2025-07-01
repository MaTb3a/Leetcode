class Solution:
    def possibleStringCount(self, word: str) -> int:
        cnt,ans = 1,0
        for i in range(1,len(word)):
            if word[i] == word[i-1]:
                cnt+=1
            else:
                ans+=cnt-1
                cnt=1
        return ans+cnt