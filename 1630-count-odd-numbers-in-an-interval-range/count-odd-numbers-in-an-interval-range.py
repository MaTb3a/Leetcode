class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if high&1:
            high+=1
        if low&1:
            low-=1
        return high//2 - low//2