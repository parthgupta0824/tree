class Solution {
public:
bool chk = 0;
    void findans(TreeNode *&root,unordered_set<int> &u,vector<TreeNode *> &ans){
        if(!root)return ;
        findans(root->left,u,ans);
        if(chk == 1){
            root->left = nullptr;
            chk = 0;
        }
        findans(root->right,u,ans);
        if(chk == 1){
            root->right = nullptr;
            chk = 0;
        }
        auto it = u.find(root->val);
        if(it != u.end()){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            chk = 1;
            return;
        }        
    }
    vector<TreeNode*> delNodes(TreeNode* r, vector<int>& d) {
        vector<TreeNode *> ans;
        if(!r)return ans;
        unordered_set<int> u;
        for(auto i : d)u.insert(i);
        findans(r,u,ans);
        auto it = u.find(r->val);
        if(it == u.end())
        ans.push_back(r);
        return ans;
    }
};