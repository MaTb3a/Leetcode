class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stk = []
        i = 0
        if(k == len(num)):
            return "0"
        
        while i < len(num):
            while k and stk and stk[-1] > num[i]:
                k-=1
                stk.pop(-1)
            stk.append(num[i])
            i+=1

        while k > 0:
            print(k)
            stk.pop(-1)
            k-=1
        while len(stk) > 1 and stk[0] == '0':
            stk.pop(0)
        return ''.join(stk)
            
            