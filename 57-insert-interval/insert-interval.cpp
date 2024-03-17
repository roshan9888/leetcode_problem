class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        // for(int i=0;i<newInterval.size();i++){
        //     vector<int> temp = {newInterval[i]};
        //     arr.push_back(temp);
        // }
        arr.push_back(newInterval);
        int n = arr.size();
        cout<<n<<" ";
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i = 0 ;i < n;i++)
        {
            if(ans.empty() ||  arr[i][0] > ans.back()[1])
            {
                ans.push_back(arr[i]);
            }
            else
            {
                ans.back()[1] = max(arr[i][1] , ans.back()[1]);
            }
        } 
        return ans ;
    }
};