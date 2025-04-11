class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        cnt = 0
        for i in range(low,high+1):
            s = str(i)
            if len(s)%2 == 0 and sum(int(s[j]) for j in range(len(s)//2)) == sum(int(s[j]) for j in range(len(s)//2,len(s))):
                cnt+=1
        return cnt