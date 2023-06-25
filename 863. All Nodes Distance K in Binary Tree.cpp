class Solution {
public:
    unordered_set<int> s;
    void parentchild(TreeNode *root,unordered_map<TreeNode *,TreeNode *> &m){
        if(!root)return ;
        if(root->left)m[root->left] = root,parentchild(root->left,m);
        if(root->right)m[root->right] = root,parentchild(root->right,m);
    }
    void findfinalans(TreeNode*&target,int k,unordered_map<TreeNode*,TreeNode*>m,unordered_set<int>&pans){
        if(!target)return ;
        auto it = pans.find(target->val);
        if(k == 0 && it == pans.end()){s.insert(target->val);return ;}
        if(it == pans.end()){
            pans.insert(target->val);
            findfinalans(target->left,k-1,m,pans);
            findfinalans(target->right,k-1,m,pans);
            findfinalans(m[target],k-1,m,pans);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> m;
        parentchild(root,m);
        unordered_set<int> u;
        findfinalans(target,k,m,u);
        vector<int> ans;
        for(auto i : s)ans.push_back(i);
        return ans;
    }
};