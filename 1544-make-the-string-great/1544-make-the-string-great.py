class Solution:
    def makeGood(self, s: str) -> str:
        i = 0
        while (i < len(s)-1):
            if ((s[i] == s[i+1].upper() and s[i].isupper() and s[i+1].islower()) or (s[i] == s[i+1].lower() and s[i].islower() and s[i+1].isupper())):
                s = s[:i] + s[i+2:]
                i = max(0,i-1)
            else:
                i+=1
        return s
                
