class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        int[] v = new int[n-1];
        
        for (int i = 1; i < n; i++) {
            v[i-1] = weights[i-1] + weights[i];
        }
        
        Arrays.sort(v);
        long ans = 0;
        
        for (int i = 0; i < k-1; i++) {
            ans += (long)v[n-2-i] - v[i];
        }
        
        return ans;
    }
}