class Solution {
    public String getHappyString(int n, int k) {
        StringBuilder ans = new StringBuilder();
        int total = 3 * (1 << (n - 1));
        if (total < k) return "";
        while (n > 0 && k > 0) {
            total = 1 << (n - 1);
            for (char ch = 'a'; ch <= 'c'; ch++) {
                if (ans.length() > 0 && ans.charAt(ans.length() - 1) == ch) continue;
                if (k > total) {
                    k -= total;
                } else {
                    ans.append(ch);
                    break;
                }
            }
            n--;
        }
        return ans.toString();
    }
}
