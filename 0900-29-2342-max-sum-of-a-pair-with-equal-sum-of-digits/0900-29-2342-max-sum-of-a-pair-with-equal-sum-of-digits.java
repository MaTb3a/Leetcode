import java.util.*;

class Solution {
    public int maximumSum(int[] nums) {
        int ans = -1;
        Map<Integer, Integer> mp = new HashMap<>();

        for (int x : nums) {
            int sumDigits = 0, tmp = x;
            while (tmp > 0) {
                sumDigits += tmp % 10;
                tmp /= 10;
            }

            if (mp.containsKey(sumDigits)) {
                ans = Math.max(ans, mp.get(sumDigits) + x);
                mp.put(sumDigits, Math.max(mp.get(sumDigits), x));
            } else {
                mp.put(sumDigits, x);
            }
        }
        
        return ans;
    }
}
