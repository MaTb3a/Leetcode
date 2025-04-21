class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        def ok(md):
            s = md
            for x in differences:
                s+=x
                if s > upper:
                    return 2
                if s < lower:
                    return 0
            return 1

        def bs_min():
            l,r,md = lower,upper,0
            while l <= r:
                md = (l+r)//2
                k = ok(md)
                if k == 1 or k == 2:
                    r = md-1
                else:
                    l = md+1
            return l

        def bs_max():
            l,r,md = lower,upper,0
            while l <= r:
                md = (l+r)//2
                k = ok(md)
                if k == 1 or k == 0:
                    l = md+1
                else:
                    r = md-1
            return l

        return bs_max() - bs_min()
        