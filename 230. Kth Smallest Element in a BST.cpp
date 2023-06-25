/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


Input: root = [3,1,4,null,2], k = 1
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 */



class Solution {
public:
int ans = -1;
    void find_inordered(TreeNode *&r,int &i,int &k){
        if(!r || ans != -1)return ;
        find_inordered(r->left,i,k);
        i++;
        if(i==k)ans = r->val;
        find_inordered(r->right,i,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        find_inordered(root,i,k);
        return ans;
    }
}; 