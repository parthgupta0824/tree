class Solution {
public:
    vector<int> findans(TreeNode *root,int &dist,int &ans){
        if(!root)return {};
        if(!root->left && !root->right){
            return {1};
        }

        
        auto l = findans(root->left,dist,ans);
        auto r = findans(root->right,dist,ans);

        for(auto i : l){
            for(auto j : r){
                if(i+j <= dist)ans++;
            }
        }


        for(int i=0;i<l.size();i++)l[i]++;
        for(int i=0;i<r.size();i++)r[i]++;

        for(auto i : l){
            r.push_back(i);
        }

        return r;


    }
    int countPairs(TreeNode* root, int dist) {
        int ans = 0;
        auto i = findans(root,dist,ans);
        return ans;
    }
};