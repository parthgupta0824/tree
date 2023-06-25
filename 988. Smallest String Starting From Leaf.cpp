class Solution {
public:
bool chk = 1;
    void findans(TreeNode *&root,string help,string &ans){
        if(!root)return ;
        char x = 'a' + root->val;
        if(!root->left && !root->right){
            help += x;
            string t = help;
            reverse(t.begin(),t.end());
            if(chk)ans = t,chk=0;
            else ans = min(ans,t);
        }


        findans(root->left,help+x,ans);
        findans(root->right,help+x,ans);

    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "",help="";
        findans(root,help,ans);
        return ans;
    }
};