class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0]>=ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=min(intervals[i][1],ans.back()[1]);
                count++;
            }
        }
        return count;
    }
};