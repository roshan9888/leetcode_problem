class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
//         //brute force
        // long long res = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     int ma = nums[i], mi = nums[i];
        //     for (int j = i; j < nums.size(); j++) {
        //         ma = max(ma, nums[j]);
        //         mi = min(mi, nums[j]);
        //         res += ma - mi;
        //     }
        // }
        // return res;

        //optimal solution
        int n=nums.size();
        vector<int>left(n,0),right(n,0);
        stack<pair<int,int>>sleft,sright;
        for(int i=0;i<nums.size();i++){
            int cnt=1;
            while(!sleft.empty() && sleft.top().first>nums[i]){
                cnt+=sleft.top().second;
                sleft.pop();
            }
            sleft.push({nums[i],cnt});
            cout<<cnt<<" ";
            left[i]=cnt;
        }
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!sright.empty() && sright.top().first>=nums[i]){
                cnt+=sright.top().second;
                sright.pop();
            }
            sright.push({nums[i],cnt});
            right[i]=cnt;
        }
        for(auto it:left){
            cout<<it<<" ";
        }
        long long x=0;
        for(int i=0;i<n;i++){
            x+=nums[i]*(long long)(left[i]*right[i]);
            // y+=nums[i]*right[i];
        }
        vector<int>left1(n,0),right1(n,0);
        stack<pair<int,int>>sleft1,sright1;
        for(int i=0;i<nums.size();i++){
            int cnt=1;
            while(!sleft1.empty() && sleft1.top().first<nums[i]){
                cnt+=sleft1.top().second;
                sleft1.pop();
            }
            sleft1.push({nums[i],cnt});
            cout<<cnt<<" ";
            left1[i]=cnt;
        }
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!sright1.empty() && sright1.top().first<=nums[i]){
                cnt+=sright1.top().second;
                sright1.pop();
            }
            sright1.push({nums[i],cnt});
            right1[i]=cnt;
        }
        long long  y=0;
        for(int i=0;i<n;i++){
            y+=nums[i]*(long long)(left1[i]*right1[i]);
        }
        return abs(x-y);
    }
};


