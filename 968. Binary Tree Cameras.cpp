class Solution {
public:
    void findans(TreeNode *&root,TreeNode *pre,int &ans){
        if(!root)return ;
        if(!root->left && !root->right)return ;        
        findans(root->left,root,ans);
        findans(root->right,root,ans);
        if((root->left && root->left->val == 0) || (root->right && root->right->val == 0)){
            root->val = 1;
            pre->val = 1;
            if(root->left)root->left->val = 1;
            if(root->right)root->right->val = 1;
            ans++;
        }
    }
    int minCameraCover(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return 1;
        int ans = 0;
        TreeNode *pre = root;
        findans(root,pre,ans);
        if(root->val == 0)ans++;
        return ans;
    }
};