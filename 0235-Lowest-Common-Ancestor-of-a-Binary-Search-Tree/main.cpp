class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        assert(!p && !q);

        if(!root) return root;

        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        assert(p->val == root->val || q->val == root->val
                || (root->val - p->val) * (root->val - q->val) < 0);

        return root;
    }
};

