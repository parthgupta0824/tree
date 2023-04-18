class Solution
{
public:
    void findlridth(TreeNode *root, int &l, int &r)
    {
        TreeNode *node = root->left;
        while (node)
            l++, node = node->left;
        node = root->right;
        while (node)
            r++, node = node->right;
    }
    void findans(TreeNode *root, vector<vector<int>> &ans, int level, int l, int r)
    {
        if (!root)
            return;
        findans(root->left, ans, level - 1, l, r);
        findans(root->right, ans, level + 1, l, r);
        int ind;
        if (level == 0)
            ind = l;
        else if (level < 0)
        {
            ind = l + level;
            else ind = l + level;
            ans[ind].push_back(root->val);
        }
        vector<vector<int>> verticalTraversal(TreeNode * root)
        {
            vector<vector<int>> ans;
            vector<vector<int>> fans;
            int l = 0, r = 0;
            findlridth(root, l, r);
            for (int i = 0; i < l + r + 1; i++)
                ans.push_back({});
            findans(root, ans, 0, l, r);
            for (int i = 0; i < ans.size(); i++)
            {
                vector<int> help = ans[i];
                sort(help.begin(), help.end());
                fans.push_back(help);
            }
            return fans;
        }
    }
};
