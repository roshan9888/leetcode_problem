class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1; 

    for (int nei : adj[node]) {
        if (visited[nei] == 0) {
            if (dfs(nei, adj, visited)) return true; 
        } 
        else if (visited[nei] == 1) {
            return true;
        }
    }

    visited[node] = 2; 
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n=numCourses;
    vector<vector<int>> adj(n);
    for (auto& e : prerequisites) {
        adj[e[0]].push_back(e[1]);
    }

    vector<int> visited(n, 0); 
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, adj, visited)) {
                return false; 
            }
        }
    }

    return true; 
    }
};