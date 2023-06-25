class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        long long  ans = 0;   
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            int sum = 0;
            for(int i=0;i<cnt;i++){
                TreeNode* node = q.front();
                if(node -> left)q.push(node -> left);
                if(node -> right)q.push(node -> right);
                sum += node -> val;
                q.pop();
            }
            ans = sum;
        }
        return ans;
    }
};