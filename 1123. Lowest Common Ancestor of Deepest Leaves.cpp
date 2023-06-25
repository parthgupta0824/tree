class Solution {
public:
    int height(TreeNode *root,int t){
        if(!root)return t;
        int l = height(root->left,t+1);
        int r = height(root->right,t+1);
        return max(l,r);
    }
    TreeNode* findnewroot(TreeNode *&root,int t,int &h){
        if(!root) return nullptr;
        if(t == h-1){
            return root;
        }

        TreeNode* l = findnewroot(root->left,t+1,h);
        TreeNode* r = findnewroot(root->right,t+1,h);
        if(!l)return r;
        if(!r)return l;
        return root;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int t = 0;
        int h = height(root,t);
        return findnewroot(root,t,h);
    }
};