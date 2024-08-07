class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<double>>pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                double div=(double) arr[i]/arr[j];
                pq.push(vector<double>{div,(double)arr[i],(double)arr[j]});
                if(pq.size()>k)
                  pq.pop();
            }
        }
        auto vec=pq.top();
        vector<int>ans(2);
        ans[0]=vec[1];
        ans[1]=vec[2];
        return ans;
    }
};