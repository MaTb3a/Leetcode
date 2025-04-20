class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i : answers) mp.put(i, mp.getOrDefault(i, 0) + 1);
        int ans = 0;
        for (Map.Entry<Integer, Integer> p : mp.entrySet())
            ans += Math.ceil((double)p.getValue() / (p.getKey() + 1)) * (p.getKey() + 1);

        return ans;
    }
}