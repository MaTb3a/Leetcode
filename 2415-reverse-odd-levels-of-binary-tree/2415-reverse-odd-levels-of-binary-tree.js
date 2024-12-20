function TreeNode(val, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
}

var reverseOddLevels = function(root) {
    const solve = (l, r, level) => {
        if (!l || !r) return;
        if (level % 2 === 1) {
            [l.val, r.val] = [r.val, l.val];
        }
        solve(l.left, r.right, level + 1);
        solve(l.right, r.left, level + 1);
    };

    solve(root.left, root.right, 1);
    return root;
};
