function TreeNode(val, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
}

var largestValues = function(root) {
    if (!root) return [];

    // Solution #1: BFS
    const q = [root];
    const ans = [];
    while (q.length) {
        const sz = q.length;
        let mx = -Infinity;
        for (let i = 0; i < sz; i++) {
            const node = q.shift();
            mx = Math.max(mx, node.val);
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        ans.push(mx);
    }

    // Solution #2: DFS
    const dfsAns = [];
    const dfs = (node, dep) => {
        if (!node) return;
        if (dfsAns.length === dep) {
            dfsAns.push(node.val);
        } else {
            dfsAns[dep] = Math.max(dfsAns[dep], node.val);
        }
        dfs(node.left, dep + 1);
        dfs(node.right, dep + 1);
    };
    dfs(root, 0);
    return dfsAns;
};
