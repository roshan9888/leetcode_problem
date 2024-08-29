// class Solution {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>>dis(n,vector<int>(n,INT_MAX));

//         for(auto it:edges){
//             dis[it[0]][it[1]]=it[2];
//             dis[it[1]][it[0]]=it[2];
//         }

//         for(int i=0;i<n;i++) dis[i][i]=0;

//         for(int k=0;k<n;k++){
//             for(int i=0;i<n;i++){
//                 for(int j=0;j<n;j++){
//                     if(dis[i][k]==INT_MAX || dis[k][j]==INT_MAX) continue;
//                     dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//                 }
//             }
//         }
//         int cntcity=n;
//         int cityno=-1;

//         for(int i=0;i<n;i++){
//             int count=0;
//             for(int j=0;j<n;j++){
//                 if(dis[i][j]<=distanceThreshold){
//                     count++;
//                 }
//             }

//             if(count<=cntcity){
//                 cntcity=count;
//                 cityno=i;
//             }
//         }
//         return cityno;
//     }
// };

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        // Result variables
        int cityNo = -1;
        int minReachable = n;

        // Run Dijkstra for each city
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.emplace(0, i);

            // Dijkstra's algorithm
            while (!pq.empty()) {
                auto [currDist, u] = pq.top();
                pq.pop();

                if (currDist > dist[u]) continue;

                for (auto& [v, weight] : adj[u]) {
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.emplace(dist[v], v);
                    }
                }
            }

            // Count reachable cities within distanceThreshold
            int reachable = 0;
            for (int j = 0; j < n; j++) {
                if (dist[j] <= distanceThreshold) {
                    reachable++;
                }
            }

            // Update city with minimum reachable cities
            if (reachable <= minReachable) {
                minReachable = reachable;
                cityNo = i;
            }
        }

        return cityNo;
    }
};