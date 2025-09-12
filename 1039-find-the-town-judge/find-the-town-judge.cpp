class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indeg(n+1,0);
        vector<int>outdegree(n+1,0);

        for(auto it:trust){
            int a=it[0];
            int b=it[1];
            outdegree[a]++;
            indeg[b]++;
        }

        for(int i=1;i<=n;i++){
            if(indeg[i]==n-1 && outdegree[i]==0){
                return i;
            }
        }
        return -1;
    }
};