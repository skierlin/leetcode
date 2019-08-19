class Solution {
public:
    int maxv=-123123632;
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        calc(root);
        return maxv;
    }
    
    
    int calc(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int temp=root->val;
        int lmaxsum=calc(root->left);
        int rmaxsum=calc(root->right);
        
        if(lmaxsum>0)
            temp+=lmaxsum;
        if(rmaxsum>0)
            temp+=rmaxsum;
        
        if(temp>maxv)
            maxv=temp;
        
        //返回以当前节点为根节点的子树的和
        return max(root->val,max(root->val+lmaxsum,root->val+rmaxsum));
            
    }
};
