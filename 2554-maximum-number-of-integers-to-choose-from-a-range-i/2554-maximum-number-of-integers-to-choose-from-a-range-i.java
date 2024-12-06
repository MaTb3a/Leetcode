import java.util.HashSet;
import java.util.Set;

class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> bannedSet = new HashSet<>();
        for (int num : banned) {
            bannedSet.add(num);  // Add banned numbers to the set
        }
        
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!bannedSet.contains(i) && i <= maxSum) {
                count++;
                maxSum -= i;
            }
        }
        
        return count;
    }
}
