class Solution {
public:
    void findans(TreeNode *root,pair<int,int> &help){
        queue<TreeNode *> q;
        q.push(root);
        int size = q.size();
        int level = 1;
        while(size){
            int sum = 0;

            while(size--){
                TreeNode *temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }

            if(sum > help.second){
                help.first = level;
                help.second = sum;
            }
            level++;
            size = q.size();

        }
    }
    int maxLevelSum(TreeNode* root) {
        pair<int,int> help;
        help.first = 0;
        help.second = INT_MIN;
        findans(root,help);
        return help.first;
    }
};