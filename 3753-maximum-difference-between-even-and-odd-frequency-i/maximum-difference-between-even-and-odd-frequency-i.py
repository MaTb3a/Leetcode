class Solution:
    def maxDifference(self, s: str) -> int:
        frq = [0]*26
        for c in s:
            frq[ord(c)-ord('a')]+=1
        oddMx,oddMn = 0,float("inf")
        evenMx,evenMn = 0,float("inf")
        for i in frq:
            if i&1:
                oddMx = max(oddMx,i)
                if i > 0 : oddMn = min(oddMn,i)
            else:
                evenMx = max(evenMx,i)
                if i > 0 : evenMn = min(evenMn,i)
        return oddMx - evenMn