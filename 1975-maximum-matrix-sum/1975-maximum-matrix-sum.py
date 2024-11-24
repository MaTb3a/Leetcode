class Solution:
    def maxMatrixSum(self, matrix):
        total_sum = 0
        min_value = float('inf')
        negative_count = 0

        for row in matrix:
            for x in row:
                total_sum += abs(x)
                min_value = min(min_value, abs(x))
                if x < 0:
                    negative_count += 1

        return total_sum - (2 * min_value if negative_count % 2 != 0 else 0)
