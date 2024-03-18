class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // int maxi=INT_MIN;
        // for(int i=0;i<points.size();i++){
        //     for(int j=0;j<points[0].size();j++){
        //         maxi=max(points[i][j],maxi);
        //     }
        // }
        // int count=0;
        // int mini=INT_MAX;
        // for(int k=0;k<maxi;k++){
        //     for(int i=0;i<points.size()-1;i++){
        //     for(int j=0;j<points[0].size()-1;j++){
        //         if(points[i][j]<=k && points[i+1][j+1]>=k){
        //             count++;
        //             points[i][j]=-1;
        //             points[i+1][j+1]=-1;
        //         }
        //     }
        //     count=min(count,mini);
        // }
        // }
        // return count;
        // vector<int>arr;
        // for(int i=0;i<points.size();i++){
        //     for(int j=0;j<points[0].size();j++){
        //         arr.push_back(points[i][j]);
        //     }
        // }

        // for(int i=0;i<arr.size()-1;i+2){
        //     if()
        // }
        // return 1;

        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        int arrows = 1;
        int end = points[0][1];
        cout<<end<<" ";

        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            } else {
                end = min(end, points[i][1]);
            }
        }
        return arrows;
    }
};