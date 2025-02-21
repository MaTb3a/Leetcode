class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class FindElements {
    constructor(root) {
        this.root = root;
        this.st = new Set();
        this.recover(this.root, 0);
    }

    recover(node, val) {
        if (!node) return;
        node.val = val;
        this.st.add(val);
        this.recover(node.left, 2 * val + 1);
        this.recover(node.right, 2 * val + 2);
    }

    find(target) {
        return this.st.has(target);
    }
}