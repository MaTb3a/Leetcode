class Solution:
    def numOfSubarrays(self, arr):
        ev, odd, total = 1, 0, 0
        for x in arr:
            total += x
            if total % 2 == 1:
                odd += 1
            else:
                ev += 1
        return (odd * ev) % 1000000007