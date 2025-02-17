
class Solution {
    boolean[] vis = new boolean[8];  
    
    private int solve(char[] tiles) {
        int ret = 1;
        for (int i = 0; i < tiles.length; i++) {
            if (vis[i] || (i > 0 && tiles[i] == tiles[i - 1] && !vis[i - 1])) continue;
            vis[i] = true;
            ret += solve(tiles);
            vis[i] = false;
        }
        return ret;
    }

    public int numTilePossibilities(String tiles) {
        char[] tileArray = tiles.toCharArray();
        Arrays.sort(tileArray); // Sort characters
        return solve(tileArray) - 1;
    }

}
