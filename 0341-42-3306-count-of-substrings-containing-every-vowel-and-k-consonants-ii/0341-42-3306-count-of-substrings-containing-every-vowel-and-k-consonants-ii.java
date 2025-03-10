class Solution {
    public long countOfSubstrings(String word, int k) {
        return solve(word, k) - solve(word, k + 1);
    }
    
    private long solve(String s, int targetK) {
        int[] mp = new int[26];
        int cons = 0;
        long ans = 0;
        int n = s.length();
        int l = 0;
        for (int r = 0; r < n; r++) {
            char c = s.charAt(r);
            if (isVowel(c)) {
                mp[c - 'a']++;
            } else {
                cons++;
            }
            while (l <= r && check(mp) && cons >= targetK) {
                ans += n - r;
                char leftC = s.charAt(l);
                if (isVowel(leftC)) {
                    mp[leftC - 'a']--;
                } else {
                    cons--;
                }
                l++;
            }
        }
        return ans;
    }
    
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    private boolean check(int[] mp) {
        return mp['a' - 'a'] > 0 && mp['e' - 'a'] > 0 && mp['i' - 'a'] > 0 && mp['o' - 'a'] > 0 && mp['u' - 'a'] > 0;
    }
}