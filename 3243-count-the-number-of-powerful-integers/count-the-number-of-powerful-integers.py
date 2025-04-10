class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        @cache
        def solve(i,tight,num):
            if i == len(num):
                return 1
            ret = 0
            mxDigit = (ord(num[i])-48) if tight else limit
            if i >= len(num) - len(s):
                d = ord(s[i-(len(num) - len(s))]) - 48
                if d <= mxDigit : ret+=solve(i+1,tight and (d == mxDigit),num)
            else:
                for d in range(0,min(limit,mxDigit)+1):
                    ret+=solve(i+1,tight and (d==mxDigit),num)
            return ret
        l = solve(0,1,str(start-1)) if start-1 >= int(s) else 0
        r = solve(0,1,str(finish)) if finish >= int(s) else 0
        return r - l
