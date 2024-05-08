class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        cpy = score[:]
        cpy.sort(reverse=True)
        dic={}
        if len(cpy) > 0:
            dic[cpy[0]] = "Gold Medal"
        if len(cpy) > 1:
            dic[cpy[1]] = "Silver Medal"
        if len(cpy) > 2:
            dic[cpy[2]] = "Bronze Medal"
        
        for i in range(3,len(cpy)):
            dic[cpy[i]] = str(i+1)
        return [dic[s] for s in score]
        