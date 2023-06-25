class Solution {
public:
    void findans(TreeNode *root,bool &ans){
        queue<TreeNode *> q;
        q.push(root);
        int size = q.size();
        bool chk = 0;
        while(size){
            int minn;
            if(chk)minn = INT_MAX; 
            else if(!chk)minn = INT_MIN;
            while(size--){
                int val = q.front()->val;
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
                if(!chk){
                    if(val <= minn || !(val & 1)){ans = 0;return;}
                    else minn = val;
                }
                else{
                    if(val >= minn || (val & 1)){ans = 0;return;}
                    else minn = val;
                }
            }
            chk = !chk;
            size = q.size();
        }
    }
    bool isEvenOddTree(TreeNode* root) {
        bool ans = 1;
        findans(root,ans);
        return ans;
    }
};