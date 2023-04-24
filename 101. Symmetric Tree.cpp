class Solution {
public:
    void chkroot(TreeNode *root1,TreeNode *root2,bool &chk){
        if((!root1 && !root2)  || !chk)     return ;
        if(!root1){chk=0;return ;}
        if(!root2){chk=0;return ;}
        if(root1->val != root2->val){
            chk =0 ;
            return ;

        }
        chkroot(root1->left,root2->right,chk);
        chkroot(root1->right,root2->left,chk);

    }
    bool isSymmetric(TreeNode* root) {
        bool chk = 1;
        chkroot(root->left,root->right,chk);
        return chk;
    }
};