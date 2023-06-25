class Solution {
public:
    // using dfs
    void findans(TreeNode *root,vector<int> &ans,int level){
        if(!root)return ;

        findans(root->left,ans,level+1);
        findans(root->right,ans,level+1);
        int size = ans.size();
        if(size <= level){
            for(int i=size;i<level+1;i++)ans.push_back(INT_MIN);
        }
        int s = ans.size();
        if(s)ans[level] = max(ans[level],root->val);
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        findans(root,ans,0);
        return ans;
    }
};



