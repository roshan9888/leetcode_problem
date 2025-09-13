class Solution {
public:
    // bool dfs(int n,vector<vector<int>>&adj,vector<bool>&v,int s){
    //     v[s]=true;

    // }
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    // 0 = not visited, 1 = visiting, 2 = visited
    visited[node] = 1; // mark as visiting

    for (int nei : adj[node]) {
        if (visited[nei] == 0) {
            if (dfs(nei, adj, visited)) return true; // cycle found
        } 
        else if (visited[nei] == 1) {
            // back edge → cycle detected
            return true;
        }
    }

    visited[node] = 2; // mark as fully visited
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<bool>visited(numCourses,0);
        // vector<vector<int>>adj(numCourses);
        // for(auto e:numCourses){
        //     adj[e[0]].push_back(e[1]);
        // }
        // for(int i=0;i<numCourses;i++){
        //     if(visited[i]==0){
        //         if(dfs(i,adj,visited)){
        //             return true;
        //         }
        //     }
        // }
        // return dfs(numCourses,adj,visited,0);
    int n=numCourses;
    vector<vector<int>> adj(n);
    for (auto& e : prerequisites) {
        adj[e[0]].push_back(e[1]);
    }

    vector<int> visited(n, 0); 
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, adj, visited)) {
                return false; // cycle → not possible
            }
        }
    }

    return true; // no cycle → possible
    }
};