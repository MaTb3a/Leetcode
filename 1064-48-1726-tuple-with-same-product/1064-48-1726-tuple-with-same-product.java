import java.util.HashMap;
import java.util.Map;

class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> productCount = new HashMap<>();
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int product = nums[i] * nums[j];
                count += productCount.getOrDefault(product, 0) * 8;
                productCount.put(product, productCount.getOrDefault(product, 0) + 1);
            }
        }

        return count;
    }
}
