class Solution {
public:
    void findactualans(TreeNode *&root,int &ts,unsigned long long int &sum,int &ans){
        if(!root)return ;
        if((sum + root->val)==ts)ans++;
        sum += root->val;
        findactualans(root->left,ts,sum,ans);
        findactualans(root->right,ts,sum,ans);
        sum -= root->val;
    }
    void finans(TreeNode *&root,int &ts,int &ans){
        if(!root)return ;
        unsigned long long int sum = 0;
        findactualans(root,ts,sum,ans);
        finans(root->left,ts,ans);
        finans(root->right,ts,ans);
    }
    int pathSum(TreeNode* root, int ts) {
        int ans = 0;
        finans(root,ts,ans);
        return ans;










        
    }
};