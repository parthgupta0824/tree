class Solution {
public:
    TreeNode *pre = nullptr;
    TreeNode *add1 = nullptr;
    TreeNode *nextadd1 = nullptr;
    TreeNode *add2 = nullptr;
    void inorder(TreeNode *root){

        if(!root)return ;
        
        inorder(root->left);
        if(pre && pre->val > root->val){
            if(!add1){
                add1 = pre;
                nextadd1 = root;
            }
            else{
                add2 = root;
            }
        }


        pre = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        // find inorder
        inorder(root);
        if(!add2) swap(add1->val,nextadd1->val);
        else swap(add1->val,add2->val);
    }
};