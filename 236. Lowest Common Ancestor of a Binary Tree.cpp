class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        else if(root == p || root == q)return root;
        TreeNode *x = lowestCommonAncestor(root->left,p,q);
        TreeNode *y = lowestCommonAncestor(root->right,p,q);
        if(!x)return y;
        else if(!y) return x;
        return root;
    }
};