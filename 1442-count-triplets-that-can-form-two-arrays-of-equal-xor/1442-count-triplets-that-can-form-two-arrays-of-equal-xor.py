class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        
        n = len(arr)
  
        for i in range(1,n):
            arr[i]=arr[i-1]^arr[i]
        
        def getXor(i,j):
            if not i:
                return arr[j]
            return arr[j]^arr[i-1]
        cnt = 0
        for i in range(0,n):
            for j in range(i+1,n):
                for k in range(j,n):
                    if getXor(i,j-1) == getXor(j,k):
                        cnt+=1
        return cnt