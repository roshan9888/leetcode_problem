class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>temp(numRows);

        for(int i=0;i<numRows;i++){
            temp[i].resize(i+1);
            temp[i][0]=temp[i][i]=1;
            for(int j=1;j<i;j++){
                temp[i][j]=temp[i-1][j-1]+temp[i-1][j];
            }
        }
        return temp;
    }
};