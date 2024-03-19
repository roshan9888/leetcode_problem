class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long res=1;
        vector<int >c;
        c.push_back(res);
        for(int i=1;i<=rowIndex;i++){
            res*=(rowIndex+1-i);
            res/=(i);
            c.push_back(res);
        }
        return c;
    }
};