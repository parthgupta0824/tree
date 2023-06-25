class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root == NULL)return {};
        vector<vector<int>> ans;
        vector<int> help;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            if(q.front() == NULL){
                ans.push_back(help);
                if(q.size() == 1)break;
                help.clear();
                q.push(NULL);
            }
            else{
                TreeNode *node = q.front();
                help.push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
}; 