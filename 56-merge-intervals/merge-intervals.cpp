class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        //brute force
    //     vector<vector<int>> ans;
    //     sort(arr.begin(),arr.end());
    //     int n=arr.size();
    //     for (int i = 0; i < n; i++) { // select an interval:
    //     int start = arr[i][0];
    //     int end = arr[i][1];

    //     //Skip all the merged intervals:
    //     if (!ans.empty() && end <= ans.back()[1]) {
    //         continue;
    //     }

    //     //check the rest of the intervals:
    //     for (int j = i + 1; j < n; j++) {
    //         if (arr[j][0] <= end) {
    //             end = max(end, arr[j][1]);
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     ans.push_back({start, end});
    // }
    // return ans;

    // time complexity O(nlogn + n^2)

    //optimal solution
    int n = arr.size();
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

        //time complexity O(n)
    }
};