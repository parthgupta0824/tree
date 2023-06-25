class Solution {
public:
    bool is_palindrom(unordered_map<char,int> &u){
        int e = 0,o=0;
        for(auto i : u){
            if(i.second % 2== 0) e++;
            else o++;
        }
        if(o>1)return 0;
        return 1;
    }
    void findans(TreeNode *&root,unordered_map<char,int> &help,int &ans){
        if(!root)return ;
        char x = '0' + root->val;
        help[x]++;
        if(!root->left && !root->right){
            bool chk = is_palindrom(help);
            if(chk)ans++;
        }
        findans(root->left,help,ans);
        findans(root->right,help,ans);
        help[x]--;
        if(help[x] == 0)help.erase(x);

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root->left && !root->right)return 1;
        unordered_map<char,int> help;
        int ans = 0;
        findans(root,help,ans);
        return ans;
    }
};