class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
         vector<int> ans;
    int m = v.size();
    int n = v[0].size();
    int totalel = m * n;
    // cout<<totalel<<" ";
    int startingrow = 0;
    int endingcol = n - 1;
    int endingrow = m - 1;
    int startingcol = 0;

    int count = 0;
    while (count < totalel)
    {
        for (int i = startingcol; i <= endingcol && count<totalel; i++)
        {
            ans.push_back(v[startingrow][i]);
            count++;
            // cout<<count<<" ";
        }
        startingrow++;
        for (int i = startingrow; i <= endingrow && count<totalel; i++)
        {
            ans.push_back(v[i][endingcol]);
            count++;
        }
        endingcol--;
        for (int i = endingcol; i >= startingcol && count<totalel; i--)
        {
            ans.push_back(v[endingrow][i]);
            count++;
        }
        endingrow--;
        for (int i = endingrow; i >= startingrow && count<totalel; i--)
        {
            ans.push_back(v[i][startingcol]);
            count++;
        }
        startingcol++;
    }
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    return ans;
    }
};