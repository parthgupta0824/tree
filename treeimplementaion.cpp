#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
    TreeNode(){
        this->val = 0;
        left = NULL;
        right = NULL;
    }
};
void postorder(TreeNode *root)
{ // fun -> 4
    // left right node
    if (root == NULL)
    {
        return;
    }
    TreeNode *node = root;
    postorder(node->left);
    postorder(node->right);
    cout << node->val << " ";
}
void preorder(TreeNode *root)
{ // fun -> 4
    // node left right
    if (root == NULL)
    {
        return;
    }
    TreeNode *node = root;
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}
void inordered(TreeNode *root)
{ // fun -> 3
    // left node right
    if (root == NULL)
    {
        return;
    }
    TreeNode *node = root;
    inordered(node->left);
    cout << node->val << " ";
    inordered(node->right);
}
void levelOrdered(TreeNode *root)
{ // fun -> 02
    // bfs
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    TreeNode *one = new TreeNode(-1);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            if (q.size() == 1)
                break;
            q.push(NULL);
            cout << endl;
        }
        else
        {
            TreeNode *node = q.front();
            cout << node->val << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        q.pop();
    }
}
TreeNode *buildtree(TreeNode *&root)
{ // fun -> 01
    cout << "Enter the val to build the tree or -1 to add NULL : ";
    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }
    TreeNode *node = new TreeNode(val);
    if (root == NULL)
    {
        root = node;
    }
    cout << "Enter the left value of " << val << " --> " << endl;
    root->left = buildtree(root->left); 
    cout << "Enter the right value of " << val << " --> " << endl;
    root->right = buildtree(root->right);
    return root;
}
// 1 2 4 -1 -1 -1 3 -1 5 -1 -1
int main()
{
    TreeNode *node = new TreeNode();
    TreeNode *root = buildtree(node);
    
    return 0;
}

