class Solution {
public:
    int find_min(vector<int>temp){
        int mini=INT_MAX;
        for(int i=0;i<temp.size();i++){
            mini=min(mini,temp[i]);
        }
        return mini;
    }

    int sumSubarrayMins(vector<int>& arr){
        //brute force 
        // int sum=0;
        // for(int start=0;start<arr.size();start++){
        //     int mini=INT_MAX;
        //     for(int end=start;end<arr.size();end++){
        //         // vector<int>temp;
        //         // for(int i=start;i<=end;i++){
        //         //     temp.push_back(arr[i]);
        //         // }
        //         mini=min(mini,arr[end]);
        //         sum=(sum+mini)%1000000007;
        //     }
        // }
        // return sum;

        //optimal solution
        int mod=1000000007;
        int n=arr.size();
        vector<int>left(n,0),right(n,0);
        stack<pair<int,int>>sleft,sright;
        for(int i=0;i<n;i++){
        int cnt=1;
            while(!sleft.empty() && sleft.top().first>arr[i]){
                cnt+=sleft.top().second;
                sleft.pop();
            }
            sleft.push({arr[i],cnt});
            left[i]=cnt;
        }
        for(int i=n-1;i>=0;i--){
        int cnt=1;
            while(!sright.empty() && sright.top().first>=arr[i]){
                cnt+=sright.top().second;
                sright.pop();
            }
            sright.push({arr[i],cnt});
            right[i]=cnt;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+(arr[i]*(long long)(left[i]*right[i])%mod)%mod)%mod;
        }
        return ans;
    }
};