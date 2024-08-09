class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix.size();
        vector<vector<int>>nm(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nm[j][n-1-i]=matrix[i][j];
            }
        }
        matrix=nm;
    }
};