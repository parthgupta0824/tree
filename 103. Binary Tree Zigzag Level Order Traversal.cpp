class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        vector<int> help;
        bool chk = 0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *t = q.front();
            if(!t){
                if(chk){
                    reverse(help.begin(),help.end());chk=0;
                }else{
                    chk = 1;
                }
                ans.push_back(help);
                help.clear();
                q.pop();
                q.push(NULL);
                if(q.size() == 1)break;
            }
            else{
                help.push_back(t->val);
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return ans;
    }
};