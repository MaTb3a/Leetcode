class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        mp = defaultdict(int)
        x,y,mx = 0,0,0
        for i in s:
            x+=i=='N'
            x-=i=='S'
            y+=i=='E'
            y-=i=='W'
            mp[i]+=1
            mx=max(mx,abs(x)+abs(y) + 2*min(k,min(mp['W'],mp['E']) + min(mp['N'],mp['S'])))


        return mx

       