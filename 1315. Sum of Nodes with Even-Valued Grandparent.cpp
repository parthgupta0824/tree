class Solution {
public:
    void findans(TreeNode *root,TreeNode *pre,TreeNode *prepre,int &ans){
        if(!root)return ;

        findans(root->left,root,pre,ans);
        findans(root->right,root,pre,ans);
        if(prepre){
            if(prepre->val % 2 == 0)ans += root->val;
        }


    }
    int sumEvenGrandparent(TreeNode* root) {
        TreeNode *pre = root;
        TreeNode *prepre = nullptr;
        int ans = 0;
        findans(root->left,pre,prepre,ans);
        findans(root->right,pre,prepre,ans);
        return ans;

    }
};