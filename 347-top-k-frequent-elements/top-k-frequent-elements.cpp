class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }
        vector<int>ans;
        int count=0;
        while(count!=k){
            ans.push_back(pq.top().second);
            count++;
            pq.pop();
        }
        return ans;
    }
};