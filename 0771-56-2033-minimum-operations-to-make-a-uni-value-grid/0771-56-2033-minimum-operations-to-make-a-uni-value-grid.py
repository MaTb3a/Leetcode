class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        mod = grid[0][0]%x
        sz = (len(grid) * len(grid[0]))
        frq = [0]*10001
        for it in grid:
            for val in it:
                if (val%x) != mod:
                    return -1
                frq[val]+=1
        
        md,ans =0,0
        for i in range(10001):
            ans+=frq[i]
            if ans*2 >= sz:
                md = i
                break
        ans =0
        for i in range(10001):
            ans+=abs(i-md)*frq[i]
        return ans//x