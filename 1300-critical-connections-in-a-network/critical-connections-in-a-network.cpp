class Solution {
public:
    void findbridges(int src,int parent,int &timer,vector<int>&tin,vector<int>&low,unordered_map<int,bool>&vis,vector<vector<int>>&ans,unordered_map<int,list<int>>&adjlist){
        vis[src]=true;
        tin[src]=timer;
        low[src]=timer;
        timer++;

        for(auto nbr:adjlist[src]){
            if(nbr==parent)
              continue;
            if(!vis[nbr]){
                findbridges(nbr,src,timer,tin,low,vis,ans,adjlist);
                low[src]=min(low[src],low[nbr]);

                if(low[nbr]>tin[src]){
                    vector<int>temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);
                }
            }
            else{
                low[src]=min(low[src],low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adjlist;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        vector<vector<int>>ans;
        int timer=1;
        vector<int>tin(n);
        vector<int>low(n);
        unordered_map<int,bool>vis;
        findbridges(0,-1,timer,tin,low,vis,ans,adjlist);
        return ans;
    }
};