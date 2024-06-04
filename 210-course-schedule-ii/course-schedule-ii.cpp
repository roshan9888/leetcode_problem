class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for (const auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
        }
       
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>topo;
        // int cnt=0;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            topo.push_back(num);
            // cnt++;

            for(auto it:adj[num]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};