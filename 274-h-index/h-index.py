class Solution:
    def hIndex(self, citations: List[int]) -> int:
       
      
        n = len(citations)
        total = 0
        frq = [0] * (n+1)
        for x in citations:
            frq[min(x,n)]+=1
        
        for i in range(n , -1,-1):
            total+=frq[i]
            if total >= i:
                return i

        return 0