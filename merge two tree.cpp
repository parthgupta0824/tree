
// solution using dfs
// very much brute force


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        // dfs 
        if(!r1 && !r2)return NULL;
        else if(!r1 && r2){
            TreeNode *n = new TreeNode(r2->val);
            n->left = mergeTrees(r1,r2->left);
            n->right = mergeTrees(r1,r2->right);
            return n;
        }
        else if(r1 && !r2){
            TreeNode *n = new TreeNode(r1->val);
            n->left = mergeTrees(r1->left,r2);
            n->right = mergeTrees(r1->right,r2);
            return n;
        }
        int val = 0;
        TreeNode* a = r1;TreeNode* b=r2;
        if(r1)val +=r1->val;
        if(r2)val +=r2->val;
        TreeNode *root = new TreeNode(val);
        root->left = mergeTrees(r1->left,r2->left);
        root->right = mergeTrees(r1->right,r2->right);
        return root;
    }
};

// using dfs
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(!r1) return r2;
        else if(!r2) return r1;
        r1 -> val += r2 -> val;
        r1->left = mergeTrees(r1->left,r2->left);
        r1->right = mergeTrees(r1->right,r2->right);
        return r1;
    }
};


// bfs 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        // bfs
        queue<TreeNode*> q1,q2;
        q1.push(r1);
        q2.push(r2);
        while(!q1.empty() && !q2.empty()){
            TreeNode *t1 = q1.front();
            TreeNode *t2 = q2.front();
            q1.pop();
            q2.pop();
            t1 -> val += t2 -> val;
            // we are not modifying the value of root1 if root2 is not present 
            if(!t1->left && t2->left){
                t1->left = t2->left;
            }
            else if(t1->left && t2->left){
                q1.push(t1->left);
                q2.push(t2->left);
            }
            if(!t1->right && t2->right){
                t1->right = t2->right;
            }
            else if(t1->right && t2->right){
                q1.push(t1->right);
                q2.push(t2->right);
            }
        }
        return r1;
    }
};