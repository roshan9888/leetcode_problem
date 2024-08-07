class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>r(numRows);

        for(int i=0;i<numRows;i++){
            r[i].resize(i+1);
            r[i][0]=r[i][i]=1;

            for(int j=1;j<i;j++){
                r[i][j]=r[i-1][j-1]+r[i-1][j];
            }
        }
        return r;
        //time complexity O(n^2)

        // for calculating the value of a given position 
        // use the formula NcK
        // for(int i=0;i<k;i++){
        //     res*=(n-i);
        //     res/=(i+1);
        // }
    }
};