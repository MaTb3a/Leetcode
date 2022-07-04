class Solution:
    def candy(self, ratings: List[int]) -> int:
        n=len(ratings)
        L=[1]*n
        R=[1]*n
        for i in range(1,n):
            if ratings[i] > ratings[i-1]:
                L[i]=L[i-1]+1
        for i in range(n-2,-1,-1):
            if ratings[i] > ratings[i+1]:
                R[i]=R[i+1]+1
        ans = 0
      
        for i in range(0,n):
            ans+=max(L[i],R[i])
        return ans