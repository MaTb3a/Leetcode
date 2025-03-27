class Solution {
    public int minimumIndex(List<Integer> nums) {
        int cnt2 = 0, x = 0;
        for (int num : nums) {
            if (cnt2 == 0) x = num;
            cnt2 += (num == x) ? 1 : -1;
        }
        
        cnt2 = 0;
        for (int num : nums) {
            if (num == x) cnt2++;
        }
        
        int n = nums.size();
        int cnt1 = 0;
        
        for (int i = 0; i < n; i++) {
            cnt1 += (nums.get(i)  == x) ? 1 : 0;
            cnt2 -= (nums.get(i)  == x) ? 1 : 0;
            
            if (cnt1 * 2 > i + 1 && cnt2 * 2 > n - (i + 1)) {
                return i;
            }
        }
        
        return -1;

    }
}