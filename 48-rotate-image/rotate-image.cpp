class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>nm(n,vector<int>(m));
        for(int i=0;i<n;i++){
            int k=m;
            // cout<<k<<" ";
            for(int j=0;j<m;j++){
                k--;
                nm[i][j]=matrix[k][i];
                cout<<nm[i][j]<<" ";
                // cout<<k<<" ";
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=nm[i][j];
            }
        } 
    }
};