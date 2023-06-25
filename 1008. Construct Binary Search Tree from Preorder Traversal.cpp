class Solution {
public:
    // non recursive code
    void findans(vector<int> &pre,stack<TreeNode *> s,int &i,TreeNode *&ans){
        ans = new TreeNode(pre[i]);
        TreeNode *temp = ans;
        s.push(ans);  
        i = 1;

        while(i < pre.size()){
            TreeNode *node = new TreeNode(pre[i]);

            if(s.top()->val > pre[i]){
                temp->left = node;
                temp = temp->left;
            }
            
            else{
                TreeNode* tadd = s.top();
                while(!s.empty() && s.top()->val < node->val){
                    tadd = s.top();
                    s.pop();                    
                }
                tadd->right = node;
            }
            s.push(node);                
            i++;

        }       
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> s;
        TreeNode* ans;
        int i = 0;
        findans(preorder,s,i,ans);
        return ans;
    }
};







// recursive 
class Solution1 {
public:
    TreeNode* buildBST(vector<int>& preorder,int& index,int lowerBound,int upperBound){
        if(index == preorder.size()) return NULL;
        if(preorder[index]<lowerBound || preorder[index]>upperBound) return NULL;
        
        TreeNode* node=new TreeNode(preorder[index++]);
        node->left=buildBST(preorder,index,lowerBound,node->val);
        node->right=buildBST(preorder,index,node->val,upperBound);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return buildBST(preorder,index,INT_MIN,INT_MAX);
    }
}; 











