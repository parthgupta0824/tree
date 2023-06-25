class Solution {
public:
bool ans = 1;
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        
        if(!r1 && !r2) {
            return 1;
        }
        else if((!r1 && r2) || (!r2 && r1))return 0;

        if(r1->val != r2->val)return 0;

        return (flipEquiv(r1->left,r2->left) && flipEquiv(r1->right,r2->right)) || (flipEquiv(r1->right,r2->left) && flipEquiv(r1->left,r2->right));


    }
};