import java.util.*;

class Solution {
    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int swp = 0;
        
        while (!q.isEmpty()) {
            int n = q.size();
            int[] v = new int[n];
            
            for (int i = 0; i < n; i++) {
                TreeNode cur = q.poll();
                v[i] = cur.val;
                if (cur.left != null) {
                    q.add(cur.left);
                }
                if (cur.right != null) {
                    q.add(cur.right);
                }
            }
            
            int[] sorted = v.clone();
            Arrays.sort(sorted);
            Map<Integer, Integer> idxMap = new HashMap<>();
            for (int i = 0; i < n; i++) {
                idxMap.put(v[i], i);
            }
            
            for (int i = 0; i < n; i++) {
                if (v[i] != sorted[i]) {
                    int idx = idxMap.get(sorted[i]);
                    idxMap.put(v[i], idx);
                    int temp = v[i];
                    v[i] = v[idx];
                    v[idx] = temp;
                    swp++;
                }
            }
        }
        
        return swp;
    }
}
