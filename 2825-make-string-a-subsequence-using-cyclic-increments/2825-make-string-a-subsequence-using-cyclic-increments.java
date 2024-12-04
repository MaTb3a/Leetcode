class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int j = 0;
        for (char c : str1.toCharArray()) {
            if (j < str2.length() && (c == str2.charAt(j) || c - str2.charAt(j) == 25 || c - str2.charAt(j) == -1)) {
                j++;
            }
        }
        return j == str2.length();
    }
}
