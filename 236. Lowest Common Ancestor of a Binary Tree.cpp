class Solution {
public:
    TreeNode* findans(TreeNode *&root,TreeNode *&p,TreeNode *&q){
        if(!root)return nullptr;
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode *l = findans(root->left,p,q);
        TreeNode *r = findans(root->right,p,q);

        if(l == nullptr){
            return r;
        }
        else if(r == nullptr)return l;
        return root;
        





    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findans(root,p,q);
    }
};