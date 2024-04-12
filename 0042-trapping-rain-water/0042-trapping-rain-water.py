class Solution:
    def trap(self, height: List[int]) -> int:
        i,Lmax,sum =0,height[0],0
        j,Rmax=len(height)-1,height[-1]
        while i < j :
            if Lmax <= Rmax:
                sum+=Lmax - height[i]
                i+=1
                Lmax = max(Lmax,height[i])
            else:
                sum+=Rmax - height[j]
                j-=1
                Rmax = max(Rmax,height[j])
        return sum