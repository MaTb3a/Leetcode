class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq ={}
        for i in s:
            if i in freq:
                freq[i]+=1
            else:
                freq[i] =1
        cnt = 0
        od = 0
        for i in freq:
            if freq[i] % 2 == 0:
                cnt+=freq[i]
            else :
                od = 1
                cnt+=freq[i]-1
        return cnt+od