class Solution {

private:
    int index;

public:
    int kthSmallest(TreeNode* root, int k) {
        index = 0;
        return kthSmallestNode(root, k)->val;
    }

private:
    TreeNode* kthSmallestNode(TreeNode* node, int k){

        if(node == NULL)
            return NULL;

        TreeNode* res = kthSmallestNode(node->left, k);
        if(res) return res;

        index ++;
        if(index == k)
            return node;

        return kthSmallestNode(node->right, k);
    }
};


