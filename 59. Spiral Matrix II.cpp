class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> ans;
        vector<int> help;
        for (int i = 0; i < n; i++)help.push_back(0);
        for (int i = 0; i < n; i++)ans.push_back(help);
        int givenum = n, num = 1, row = 0, column = 0, restrictrow = n, newrowcol = n;
        while (givenum * givenum > num){
            while (column < restrictrow)ans[row][column++] = num++;
            row++;
            column--;
            newrowcol = row;
            while (row < restrictrow)ans[row++][column] = num++;
            row--;
            column--;
            while (column >= newrowcol - 1)ans[row][column--] = num++;
            row--;
            column = newrowcol - 1;
            while (row >= newrowcol)ans[row--][column] = num++;
            restrictrow = n - 1;
            n--;
            row = newrowcol;
            column = newrowcol;
        }
        if (givenum % 2)ans[givenum / 2][givenum / 2] = givenum * givenum;
        return ans;
    }
};
