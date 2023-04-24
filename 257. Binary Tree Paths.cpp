class Solution {
public:
    void findans(TreeNode *root,vector<string> &ans,string help){
        if(!root->left && !root->right){
            ans.push_back(help+to_string(root->val));
            return;
        }
        else{
            if(root->left)findans(root->left,ans,help+to_string(root->val)+"->");
            if(root->right)findans(root->right,ans,help+to_string(root->val)+"->");
        }       
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> ans;
        findans(root,ans,"");
        return ans;
    }
};


#include <iostream>
using namespace std;
void heapify(int arr[], int N, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest]){
        largest = l;
    }
    if (r < N && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N){
    for (int i = N / 2 - 1; i >= 0; i--){
        heapify(arr, N, i);        
    }
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

