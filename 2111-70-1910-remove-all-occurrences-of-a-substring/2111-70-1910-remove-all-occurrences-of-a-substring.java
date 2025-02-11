class Solution {
    public String removeOccurrences(String s, String part) {
        int sz = part.length();
        int[] lps = new int[sz];
        
        // KMP Preprocessing
        int j = 0;
        for (int i = 1; i < sz; i++) {
            while (j > 0 && part.charAt(i) != part.charAt(j)) {
                j = lps[j - 1];
            }
            if (part.charAt(i) == part.charAt(j)) {
                lps[i] = ++j;
            }
        }

        StringBuilder ans = new StringBuilder();
        int[] stk = new int[s.length()];
        j = 0;
        int idx = 0;

        for (char ch : s.toCharArray()) {
            ans.append(ch);
            stk[idx++] = j;

            while (j > 0 && ch != part.charAt(j)) {
                j = lps[j - 1];
            }

            if (ch == part.charAt(j)) {
                j++;
            }

            stk[idx - 1] = j;

            if (j == sz) {
                ans.setLength(ans.length() - sz);
                idx -= sz;
                j = (idx > 0) ? stk[idx - 1] : 0;
            }
        }

        return ans.toString();
    }
}
