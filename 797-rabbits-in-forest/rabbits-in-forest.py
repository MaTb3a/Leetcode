class Solution(object):
    def numRabbits(self, answers):
        mp = Counter(answers)
        ans = 0
        for x in mp:
            ans += ceil(float(mp[x]) / (x + 1)) * (x + 1)
        return int(ans)