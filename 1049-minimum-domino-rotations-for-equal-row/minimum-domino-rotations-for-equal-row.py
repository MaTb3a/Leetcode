class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def solve(t,b,cur):
            cnt1,cnt2 = 0,0
            for i in range(len(tops)):
                if cur != t[i] and cur != b[i]:
                    return int(1e9)
                if cur != b[i]:
                    cnt1+=1
                if cur != t[i]:
                    cnt2+=1
            return min(cnt1,cnt2)
        
        ans = min(solve(tops,bottoms,tops[0]),solve(tops,bottoms,bottoms[0]))
        return ans if ans != int(1e9) else -1