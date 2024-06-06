class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        st = Counter(hand)
        while len(st) > 0:
            mn = min(st)
            for i in range(mn,mn+groupSize):
                if i in st:
                    st[i]-=1
                else:
                    return False
                if st[i] == 0:
                    del st[i]
        return True