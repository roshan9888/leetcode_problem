class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int currtime=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(currtime>time[node]) continue;


            for(auto it:adj[node]){
                int next=it.first;
                int timetaken=it.second;
                if(currtime+timetaken < time[next]){
                pq.push({currtime+timetaken,next});
                time[next]=currtime+timetaken;
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,time[i]);
        }
        return (ans!=INT_MAX) ? ans : -1;
    }
};