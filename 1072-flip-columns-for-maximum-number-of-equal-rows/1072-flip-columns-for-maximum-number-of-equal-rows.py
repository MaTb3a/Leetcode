class Solution:
    def maxEqualRowsAfterFlips(self, matrix):
        m = len(matrix[0])
        max_count = 0
        freq = defaultdict(int)
        
        for row in matrix:
            original = "".join(str(cell) for cell in row)
            flipped = "".join(str(1 - cell) for cell in row)
            freq[original] += 1
            freq[flipped] += 1
            max_count = max(max_count, freq[original], freq[flipped])
        
        return max_count
