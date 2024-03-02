class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0){
           int setbit=n&1;
        if(setbit){
            count++;
        }
        n=n>>1;
        }
        return count;
    }
};