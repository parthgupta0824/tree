class Solution {
public:
    void findans(TreeNode *root,map<int,map<int,multiset<int>>> &help,int level,int height){
        if(!root) return ;
        findans(root->left,help,level-1,height+1);
        findans(root->right,help,level+1,height+1);
        help[level][height].insert(root->val);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> help;
        int level = 0,height=0;
        findans(root,help,level,height);
        for(auto i : help){
            vector<int> x;
            for(auto j : i.second){
                for(auto k : j.second)x.push_back(k);
            }
            ans.push_back(x);
        }
        return ans;       
    }
};