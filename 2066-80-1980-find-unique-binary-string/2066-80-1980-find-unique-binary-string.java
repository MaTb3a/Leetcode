
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < nums.length; i++) {
            s.append(nums[i].charAt(i) == '0' ? '1' : '0');
        }
        return s.toString();
    }
}
