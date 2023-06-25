class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        queue<pair<int,TreeNode*>> q;
        unordered_map<int,int> u;
        q.push({0,root});
        while(!q.empty()){
            pair<int,TreeNode*> p = q.front();
            q.pop();
            auto it = u.find(p.first);
            if(it == u.end()) ans.push_back(p.second->val),u[p.first] = p.second->val;
            if(p.second->right) q.push({p.first+1,p.second->right});
            if(p.second->left) q.push({p.first+1,p.second->left});
            // left me bhi +1 karke hum 
        }
        return ans;
    }
};