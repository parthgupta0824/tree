class Solution {
public:
    void findminmax(TreeNode *root,int minn,int maxx,int &ans){
        if(!root)return ;
        minn = min(minn,root->val);
        maxx = max(maxx,root->val);
        findminmax(root->left,minn,maxx,ans);
        findminmax(root->right,minn,maxx,ans);
        ans = max(ans,abs(root->val-maxx));
        ans = max(ans,abs(root->val-minn));
    }
    int maxAncestorDiff(TreeNode* root) {
        int minn = INT_MAX;
        int maxx = INT_MIN;
        int ans = INT_MIN;
        findminmax(root,minn,maxx,ans);
        return ans;
    }
};


                //      8
                //     / \
                //   7     10
                //  / \    / \    
                // 5   6  9  20
                 