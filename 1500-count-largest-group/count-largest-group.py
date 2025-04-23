class Solution:
    def countLargestGroup(self, n: int) -> int:
        dic = dict()
        for i in range(1,n+1):
            s,x = 0,i
            while x:
                s+=x%10
                x//=10
            if s in dic:
                dic[s]+=1
            else:
                dic[s] = 1

        dic2 = dict()
        mx = 1

        for k in dic:
            if dic[k] in dic2:
                dic2[dic[k]]+=1
            else:
                dic2[dic[k]] = 1
            mx=max(mx,dic[k])
        print(dic,dic2)
        return dic2[mx]               
