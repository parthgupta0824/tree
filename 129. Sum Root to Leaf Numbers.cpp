class Solution {
public:
    void findans(TreeNode *&root,string &help,int &ans){
        if(!root)return ;
        help += '0' + root->val;
        if(!root->left && !root->right) ans += stoi(help);
        findans(root->left,help,ans);
        findans(root->right,help,ans);
        help.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string help = "";
        int ans = 0;
        findans(root,help,ans);
        return ans;
    }
};