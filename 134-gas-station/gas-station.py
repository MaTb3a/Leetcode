class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        start,mn = -1,-1
        tank = 0
        for i in range(len(gas)):
            tank+=gas[i] - cost[i]
            if tank >= 0:
                if start == -1:
                    start = i
            else:
                tank =0
                start = -1
            
        for i in range(0,start+1):
            tank+=gas[i] - cost[i]
            if tank < 0:
                return -1
        
     
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


