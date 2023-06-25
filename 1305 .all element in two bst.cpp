

/*
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

Constraints:

The number of nodes in each tree is in the range [0, 5000].
-10^5 <= Node.val <= 10^5


----------- try doing it in O(n)

*/







// with using multiset (brut_force)

class Solution {
public:
    void findans(TreeNode* r,multiset<int> &help){
        if(!r)return ;
        help.insert(r->val);
        findans(r->left,help);
        findans(r->right,help);
    }
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        vector<int> ans;
        multiset<int> help;
        findans(r1,help);
        findans(r2,help);
        for(auto i : help)ans.push_back(i);
        return ans;
    }
};


















// using inorder

class Solution {
public:
    void find_inordered(TreeNode *&r,vector<int> &v){
        if(!r)return ;
        find_inordered(r->left,v);
        v.push_back(r->val);
        find_inordered(r->right,v);
    }
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        // just find the inorder of each node
        vector<int> v1,v2;
        find_inordered(r1,v1);
        find_inordered(r2,v2);
        vector<int> ans;
        int i=0,j=0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i] < v2[j]) ans.push_back(v1[i++]);
            else if(v1[i] > v2[j]) ans.push_back(v2[j++]);
            else{
                ans.push_back(v2[j]);
                ans.push_back(v2[j]);
                i++;j++;
            }
        }
        while(i<v1.size()) ans.push_back(v1[i++]);
        while(j<v2.size()) ans.push_back(v2[j++]);
        return ans;
    }
};