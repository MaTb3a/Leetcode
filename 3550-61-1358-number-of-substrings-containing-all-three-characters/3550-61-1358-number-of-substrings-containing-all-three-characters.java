class Solution {
    public int numberOfSubstrings(String s) {
        int[] vis = {-1, -1, -1}; 
        int cnt = 0; 

        for (int i = 0; i < s.length(); i++) {
            vis[s.charAt(i) - 'a'] = i; 
            int minIndex = Math.min(vis[0], Math.min(vis[1], vis[2]));
            cnt += minIndex + 1;
        }

        return cnt;
    }
}