class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        
        n = len(profit)
        lst = [[0, 0] for _ in range(n)]

        for i in range(n):
            lst[i] = [difficulty[i],profit[i]]
        lst.sort()
        for i in range(1,n):
            lst[i][1] = max(lst[i-1][1],lst[i][1])
        worker.sort()
        ans = 0
        idx = 0
        mx = 0
        for x in worker:
            while idx < n and lst[idx][0] <= x:
                mx=max(mx,lst[idx][1])
                idx+=1
            ans+=mx
        return ans