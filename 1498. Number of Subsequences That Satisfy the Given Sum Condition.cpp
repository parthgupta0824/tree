#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define umii unordered_map<int, int>
#define umci unordered_map<char, int>
#define umsi unordered_map<string, int>
#define usi unordered_set<int>
#define usc unordered_set<char>
#define uss unordered_set<string>
long long power(int t, int x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return t;
    long long ans = 1;
    if (x % 2 == 0)
    {
        ans = power(t, x / 2);
        ans *= ans;
    }
    else
    {
        ans = power(t, x - 1);
        ans *= t;
    }
    return ans % 1000000007;
}

int numSubseq(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    long long ans = 0;
    int i = 0, j = nums.size() - 1;
    while (i <= j)
    {
        if (nums[i] + nums[j] <= target)
        {
            int x = j - i;
            // int y = pow(2,x); // not able to handle large values
            long long y = power(2, x);
            ans += y;
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans % 1000000007;
}
int main()
{
    int n, x, t;
    cin >> n;
    vi v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.pb(x);
    }
    cin >> t;
    cout << numSubseq(v, t);

    return 0;
}