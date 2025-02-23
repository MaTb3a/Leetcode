var constructFromPrePost = function(preorder, postorder) {
    const stk = [];
    const root = new TreeNode(preorder[0]);
    stk.push(root);
    let i = 1, j = 0;
    
    while (stk.length) {
        const cur = stk[stk.length - 1];
        if (cur.val === postorder[j]) {
            stk.pop();
            j++;
            continue;
        }
        const node = new TreeNode(preorder[i++]);
        if (!cur.left) cur.left = node;
        else cur.right = node;
        stk.push(node);
    }
    return root;
};