class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: # handle case
            return s

        ans = [''] * numRows # [''] [''] ['']
        idx,d = 0,1

        for c in s:
            ans[idx]+=c
            if idx == 0:
                d = 1
            elif idx == numRows-1:
                d = -1
            idx+=d

        return ''.join(ans)