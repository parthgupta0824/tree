class Solution {
public: 
    TreeNode* findroot(ListNode *start,ListNode *end){
        if(start == end)return nullptr;
        ListNode *slow = start;
        ListNode *fast = start;
        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = findroot(start,slow);
        root->right = findroot(slow->next,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return nullptr;
        return findroot(head,nullptr);
    }
};