class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time = 0
        for i in range(0,len(tickets)):
            if i <= k :
                time+=min(tickets[k],tickets[i])
            else:
                time+=min(tickets[k]-1,tickets[i])
        return max(time,0)
            