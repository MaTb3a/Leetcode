class Solution {
    public String smallestNumber(String pattern) {
        int n = pattern.length();
        StringBuilder stk = new StringBuilder(), ans = new StringBuilder();
        for (int i = 0; i <= n; i++) {
            stk.append(i + 1);
            if (i == n || pattern.charAt(i) == 'I') {
                ans.append(stk.reverse());
                stk.setLength(0);
            }
        }
        return ans.toString();
    }
}
