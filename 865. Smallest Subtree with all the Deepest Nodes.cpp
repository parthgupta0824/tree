class Solution {
public:
int height = 1;
    void findheight(TreeNode *&root,int h){
        if(!root)return ;
        height = max(height,h);
        findheight(root->left,1+h);
        findheight(root->right,h+1);
    }
    TreeNode* findans(TreeNode *root,TreeNode *pre,int h){
        if(!root)return nullptr;
        if(!root->left && !root->right){
            if(h == height) return root;
        }
        TreeNode *l = findans(root->left,root,h+1);
        TreeNode *r = findans(root->right,root,h+1);
        if(l && r)return root;
        if(l)return l;
        if(r)return r;
        return nullptr;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)return root;
        if(!root->left && !root->right)return root;
        int h = 0;
        findheight(root,h);
        TreeNode *pre = root;
        return findans(root,pre,0);
    }
};