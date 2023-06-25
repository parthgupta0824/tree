class Solution {
public:
    TreeNode* findans(TreeNode *&root,int &limit,int sum){
        if(!root)return nullptr;
        if(!root->left && !root->right){
            if(sum+root->val < limit) return nullptr;
            else return root;
        }
        TreeNode* left = findans(root->left,limit,sum+root->val);
        TreeNode* right = findans(root->right,limit,sum+root->val);
        if(!left)root->left = nullptr;
        if(!right)root->right = nullptr;
        if(!left && !right)return nullptr;
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return findans(root,limit,0);
    }
};
