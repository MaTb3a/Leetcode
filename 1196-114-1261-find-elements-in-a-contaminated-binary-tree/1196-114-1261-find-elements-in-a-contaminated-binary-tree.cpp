
class FindElements {
public:
    TreeNode* tree;
    FindElements(TreeNode* root) {
        tree = root;
    }
    
    bool find(int target) {
        bitset<21>bt(target+1);
        int idx = 20;
        while(!bt[idx])idx--;
        TreeNode* cp = tree;
        while(--idx >=0 && cp)
            if(bt[idx])cp = cp->right;
            else cp = cp->left;
        return idx == -1 && cp;
        
    }
};
