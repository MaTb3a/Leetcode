class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        dic = defaultdict(int)
        for x in dominoes:
            key = tuple(sorted(x)) 
            dic[key]+=1
        ans = 0
        for key,value in dic.items():
            if value > 1:
                ans+=value*(value-1)//2
        return ans