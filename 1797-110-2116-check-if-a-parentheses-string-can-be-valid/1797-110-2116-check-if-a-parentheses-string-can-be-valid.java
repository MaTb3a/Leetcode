class Solution {
    private boolean solve(String s, String locked, boolean forward) {
        int cnt = 0, magic = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int idx = forward ? i : n - i - 1;

            if (locked.charAt(idx) == '0') {
                magic++;
                continue;
            }

            if ((s.charAt(idx) == '(' && forward) || (s.charAt(idx) == ')' && !forward)) {
                cnt++;
            } else {
                if (cnt > 0) {
                    cnt--;
                } else if (magic > 0) {
                    magic--;
                } else {
                    return false;
                }
            }
        }

        return true;
    }

    public boolean canBeValid(String s, String locked) {
        if (s.length() % 2 != 0) {
            return false;
        }
        return solve(s, locked, true) && solve(s, locked, false);
    }
}
