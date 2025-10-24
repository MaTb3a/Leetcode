class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        for i in range(n+1,1224445):
            mp = Counter(str(i))
            ok = True
            for key,val in mp.items():
                if int(key) != int(val):
                    ok = False
                    break
            if ok == True:
                return i
