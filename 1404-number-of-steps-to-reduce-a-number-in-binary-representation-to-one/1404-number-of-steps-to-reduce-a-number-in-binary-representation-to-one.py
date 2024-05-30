class Solution:
    def numSteps(self, s: str) -> int:
        cnt = 0
        s=list(s)
        def addOne(s):
            for i in range(len(s)-1,-1,-1):
                add = True
                if s[i] == '0':
                    add = False
                    s[i]='1'
                    break
                else:
                    s[i]='0'
            if add:
                s.insert(0,'1')

            return s
        while len(s) > 1:
            if s[-1] == '0':
                s.pop(-1)
            else:
                s = addOne(s)
            cnt+=1
       
        return cnt