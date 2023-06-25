class Solution {
public:
    void findans(TreeNode *&root,int &fs,int sum,vector<int> &help,vector<vector<int>> &ans){
        if(!root) return ;
        help.push_back(root->val);
        sum += root->val;
        if(sum == fs && !root->left && !root->right) ans.push_back(help);
        findans(root->left,fs,sum,help,ans);
        findans(root->right,fs,sum,help,ans);
        sum -= root->val;
        help.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> help;
        findans(root,targetSum,sum,help,ans);
        return ans;
    }
};