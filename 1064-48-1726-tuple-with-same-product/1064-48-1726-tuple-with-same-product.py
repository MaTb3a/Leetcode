from collections import defaultdict

class Solution:
    def tupleSameProduct(self, nums):
        product_count = defaultdict(int)
        count = 0

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                product = nums[i] * nums[j]
                count += product_count[product] * 8
                product_count[product] += 1

        return count
