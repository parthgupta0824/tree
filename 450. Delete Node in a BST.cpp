class Solution {
public:
bool chk = 0;
TreeNode *x = nullptr;
    void findkey(TreeNode *&root,int &key,TreeNode *&parent,TreeNode *&lhelp,TreeNode *&rhelp){
        if(!root || chk)return ;
        if(root->val == key){
            chk = 1;
            x = parent;
            lhelp = root -> left;
            rhelp = root -> right;
            return ;            
        }
        parent = root;
        findkey(root->left,key,parent,lhelp,rhelp);
        parent = root;
        findkey(root->right,key,parent,lhelp,rhelp);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        TreeNode *parent = root;
        TreeNode *lhelp = nullptr;
        TreeNode *rhelp = nullptr;
        if(root->val == key){
            TreeNode *x = nullptr;
            if(root->left){
                x = root->right;
                root = root->left;
                TreeNode *help = root;
                while(help->right)help = help->right;
                help->right = x;
            }
            else if(root->right){
                x = root->left;
                root = root->right;
                TreeNode *help = root;
                while(help->left)help = help->left;
                help->left = x;
            }
            else {
                return nullptr;
            }
            return root;
        }

        findkey(root,key,parent,lhelp,rhelp);
        parent = x;
        if(!chk)return root;
        if(!lhelp && !rhelp){
            cout<<parent -> val<<endl;
            if(parent->left && parent -> left -> val == key)parent -> left = nullptr;
            else parent -> right = nullptr;
        }
        else if(!lhelp){
            if(parent->left && parent -> left -> val == key) parent -> left = parent -> left -> right;
            else parent -> right = parent -> right -> right;
        }
        else if(!rhelp){
            if(parent->left && parent -> left -> val == key)parent -> left = parent -> left -> left;
            else parent -> right = parent -> right -> left;
        }
        else{ // both child are present 
            TreeNode *temp = nullptr;
            if(parent->left && parent -> left -> val == key){
                temp = parent -> left -> right;//7
                parent -> left -> right = nullptr;
                parent -> left = parent -> left -> left; // 3
                while(lhelp->right)lhelp = lhelp -> right;
                lhelp -> right = temp;
            }
            else {
                temp = parent -> right -> left;//18
                parent -> right -> left = nullptr;
                parent -> right = parent -> right -> right; // 3
                while(rhelp->left)rhelp = rhelp -> left;
                rhelp -> left = temp;
            }
        }
        return root;
    }
};