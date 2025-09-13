class Solution:
    def maxFreqSum(self, s: str) -> int:
        freq = {}
        for c in s:
            if c in freq:
                freq[c]+=1
            else:
                freq[c] = 1
        mx1,mx2 = 0,0
        for key,val in freq.items():
            if key == 'a' or key == 'e' or key == 'i' or key == 'u' or key == 'o':
                mx1=max(mx1,val)
            else:
                mx2=max(mx2,val)
        return mx1+mx2

