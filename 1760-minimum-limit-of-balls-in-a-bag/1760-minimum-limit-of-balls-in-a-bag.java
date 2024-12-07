import java.util.*;

class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        int left = 1, right = Arrays.stream(nums).max().getAsInt(), result = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canDivide(nums, maxOperations, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    private boolean canDivide(int[] nums, int maxOperations, int mid) {
        int operations = 0;
        for (int bag : nums) {
            operations += (bag - 1) / mid;
        }
        return operations <= maxOperations;
    }
}
