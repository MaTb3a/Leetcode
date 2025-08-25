class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        
        start,tank = 0,0
        for i in range(len(gas)):
            tank+=gas[i] - cost[i]
            if tank < 0:
                tank =0
                start = i+1
       

        return start
        # 5, 8,2 ,8
        # 6, 5,6 ,6
        # -1 3 -4 2
        # -1 2 -2 0

        # 1 ,2 ,3 ,4 ,5
        # 3 ,4 ,5 ,1 ,2
        # 
        # -2 -2 -2 3 ,3
        # -2 -4 -6 -3 0

        # 2 ,3 ,4
        # 3 ,4 ,3
        # -1 -1 1
        # -1 -2 -1


