class Solution:
    def countLargestGroup(self, n: int) -> int:
        mp = Counter()
        for i in range(1,n+1):
            s = sum(int(x) for x in str(i))
            mp[s]+=1
            mx=max(mp.values())
        
        return sum(1 for v in mp.values() if v == mx)