class Solution {
    int mod=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<long long>wt(n,1e15);
        vector<int>way(n,0);
        priority_queue<pair<long long, int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        
        pq.push({0,0});
        wt[0]=0;
        way[0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            long long  dis=it.first;
            int node=it.second;

            if(node==n-1) break;

            for(auto it:adj[node]){
                int newnode=it.first;
                long long ndis=it.second;

                if(ndis+dis<wt[newnode]){
                    wt[newnode]=ndis+dis;
                    way[newnode]=way[node];
                    pq.push({ndis+dis,newnode});
                }
                else if(ndis+dis==wt[newnode]){
                    way[newnode]=(way[newnode]+way[node]*1LL)%mod;
                }
            }
        }
        return way[n-1];
    }
};