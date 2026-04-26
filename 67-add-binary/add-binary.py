class Solution:
    def addBinary(self, a: str, b: str) -> str:
        s = ''
        flag = 0
        a = list(a)
        b = list(b)
        while len(a) and len(b):
            if int(a[-1]) + int(b[-1]) + flag == 3:
                flag = 1
                s+=('1')
            elif int(a[-1]) + int(b[-1]) + flag == 2:
                flag = 1
                s+=('0')
            elif int(a[-1]) + int(b[-1]) + flag == 1:
                flag = 0
                s+=('1')
            else:
                flag = 0
                s+=('0')
            a.pop(-1)
            b.pop(-1)
        
        while len(a):
            if int(a[-1]) + flag == 2:
                flag = 1
                s+='0'
            elif int(a[-1]) + flag == 1:
                flag = 0
                s+='1'
            else :
                flag = 0
                s+='0'
            a.pop(-1)
        
        while len(b):
            if int(b[-1]) + flag == 2:
                flag = 1
                s+='0'
            elif int(b[-1]) + flag == 1:
                flag = 0
                s+='1'
            else :
                flag = 0
                s+='0'
            b.pop(-1)
        
        if flag:
            s+='1'
        return s[::-1]

            
