class Solution {
public:
bool chk = 0;
    void findans(TreeNode *&root,vector<int> &v,TreeNode *&pre,int &i,vector<int> &ans){
        if(i == v.size() || chk || !root){
            return ;
        }
        if(root && root->val != v[i] && pre){
            if((pre->left && pre->left->val == v[i]) || (pre->right && pre->right->val == v[i])){
                ans.push_back(pre->val);
                swap(pre->left , pre->right);
            }
            else{
                ans.clear();
                ans.push_back(-1);
                chk = 1;
            }
        }
        i++;
        findans(root->left,v,root,i,ans);
        findans(root->right,v,root,i,ans);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        vector<int> ans;
        if(!root)return ans;
        TreeNode *pre = nullptr;
        int i = 0;
        findans(root,v,pre,i,ans);
        return ans;
    }
};