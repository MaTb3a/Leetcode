class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        
        idx,d = 0,1
        rows = [''] * numRows

        for c in s:
            rows[idx] +=c
            if idx == 0:
                d =1
            elif idx == numRows -1:
                d = -1
            idx +=d
        return ''.join(rows)