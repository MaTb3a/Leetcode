import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int i = 0, j = 0;
        int n = nums1.length, m = nums2.length;
        List<int[]> result = new ArrayList<>();

        while (i < n || j < m) {
            // Get the current IDs or infinity if one array is exhausted
            int id1 = i < n ? nums1[i][0] : Integer.MAX_VALUE;
            int id2 = j < m ? nums2[j][0] : Integer.MAX_VALUE;

            if (id1 < id2) {
                // Append the element from nums1
                result.add(nums1[i]);
                i++;
            } else if (id2 < id1) {
                // Append the element from nums2
                result.add(nums2[j]);
                j++;
            } else {
                // Merge the elements with the same ID
                result.add(new int[]{id1, nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }

        // Convert List<int[]> to int[][]
        int[][] output = new int[result.size()][2];
        for (int k = 0; k < result.size(); k++) {
            output[k] = result.get(k);
        }
        return output;
    }
}