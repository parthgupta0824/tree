class Solution {
public:
typedef unsigned long long int ull;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<ull,TreeNode*>> q;
        TreeNode *node = root;
        q.push({0,root});
        ull ans = 0;
        while(!q.empty()){ 
            pair<ull,TreeNode *> p = q.front();
            ull x = q.front().first , y = q.back().first;
            ans = max(ans,y-x+1);
            x = q.size();
            while(x--){
                y = q.front().first;
                if(q.front().second->left)q.push({y*2+1,q.front().second->left});
                if(q.front().second->right)q.push({y*2+2,q.front().second->right});
                q.pop();
            }            
        }
        return ans;
    }
};