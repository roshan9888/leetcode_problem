class Solution {
public:
int countSetBits(int n) {
  int count = 0;
  while(n !=0) {
    int lastBit = n & 1;
    if(lastBit)
      count++;
    //right shift
    n = n >> 1;
  }
  return count;
}

    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(countSetBits(i));
        }
        return ans;
    }
};