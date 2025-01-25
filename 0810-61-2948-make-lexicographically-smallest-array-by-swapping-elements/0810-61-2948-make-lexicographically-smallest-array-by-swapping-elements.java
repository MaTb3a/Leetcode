import java.util.*;

class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        List<int[]> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            v.add(new int[]{nums[i], i});
        }
        v.sort(Comparator.comparingInt(a -> a[0]));

        int i = 0;
        while (i < n) {
            List<Integer> idx = new ArrayList<>();
            idx.add(v.get(i)[1]);
            int j = i + 1;
            while (j < n && v.get(j)[0] - v.get(j - 1)[0] <= limit) {
                idx.add(v.get(j)[1]);
                j++;
            }
            Collections.sort(idx);
            for (int k = 0; k < idx.size(); k++) {
                nums[idx.get(k)] = v.get(i + k)[0];
            }
            i = j;
        }

        return nums;
    }
}
