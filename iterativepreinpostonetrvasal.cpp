#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> inorderTraversal(TreeNode *root)
{

    vector<vector<int>> ans;
    vector<int> pre, in, post;
    stack<pair<TreeNode *, int>> s;
    s.push({root, 1});
    pair<TreeNode *, int> p;
    while (!s.empty())
    {
        if (s.top().second == 1)
        {
            pre.push_back(s.top().first->val);
            s.top().second++;
            if (s.top().first->left)
            {
                s.push({s.top().first->left, 1});
            }
        }
        else if (s.top().second == 2)
        {
            in.push_back(s.top().first->val);
            s.top().second++;
            if (s.top().first->right)
            {
                s.push({s.top().first->right, 1});
            }
        }
        else
        {
            post.push_back(s.top().first->val);
            s.pop();
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

int main()
{
    return 0;
}