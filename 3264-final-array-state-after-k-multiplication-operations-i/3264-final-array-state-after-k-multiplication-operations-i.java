import java.util.*;

class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        TreeSet<int[]> st = new TreeSet<>((a, b) -> {
            if (a[0] == b[0]) return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });

        for (int i = 0; i < nums.length; i++) {
            st.add(new int[] { nums[i], i });
        }

        while (k-- > 0) {
            int[] smallest = st.pollFirst();
            int idx = smallest[1];
            nums[idx] *= multiplier;
            st.add(new int[] { nums[idx], idx });
        }

        return nums;
    }
}
