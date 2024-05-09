class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        ans = 0
        negatives = 0
        for i in range(0,k):
            if happiness[i] < i:
                negatives+=1
            else:
                ans+=happiness[i]
        k-=negatives
        return ans-(k*(k-1)//2)
       