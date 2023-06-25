class Solution {
public:
int level = 1;
TreeNode *pre;
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == level){
            TreeNode *newnode = new TreeNode (val);
            if(depth == 1){
                newnode->left = root;
                return newnode;
            }
            if(pre && pre->left == root)newnode->left = root;
            else if(pre && pre->right == root)newnode->right = root;
            return newnode;
        }
        if(!root)return nullptr;
        level++;
        pre = root;
        root->left = addOneRow(root->left , val,depth);
        root->right = addOneRow(root->right , val,depth);
        level--;
        return root;
    }
};

 