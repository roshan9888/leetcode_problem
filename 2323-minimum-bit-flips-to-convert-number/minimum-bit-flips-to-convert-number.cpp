class Solution {
public:
  
  int getithBit(int n , int i) {
  int mask = 1 << i;
  int ans = n & mask;
  if(ans == 0)
    return 0;
  else
    return 1;
}

    int minBitFlips(int start, int goal) {
        int count=0;
        // int numberOfBits1 = static_cast<int>(ceil(log2(start)));
        // int numberOfBits2 = static_cast<int>(ceil(log2(goal)));
        // int numberOfBits=max(numberOfBits1,numberOfBits2);
        for(int i=0;i<32;i++){
           if(getithBit(start,i)!=getithBit(goal,i)){
               count++;
           }
        }
        return count;
    }
};