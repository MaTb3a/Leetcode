class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i,j,c = len(a)-1,len(b)-1,0
        res = ''
        while i >= 0 or j >= 0 or c:
            if i >= 0:
                c += int(a[i])
            if j >= 0:
                c += int(b[j])
            i-=1
            j-=1
            res +=str(c%2)
            c = c // 2
        return res[::-1]