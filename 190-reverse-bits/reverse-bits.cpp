class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //brute force
        // string bits="";
        // for(int i=0;i<32;i++){
        //     if(n& (i<<i)) bits.push_back('1');
        //     else bits.push_back('0');
        // }
        
        // uint32_t ans=0;
        // for(int i=31;i>=0;i--){
        //     if(bits[i++]=='1') ans=ans | (1>>i);
        // }
        // return ans;

        //optimal soution
        uint32_t x = 0 ;
    for( int i = 0 ; i < 32; i ++) {
        x = x * 2 +n%2;
        n/=2;
    }
    return x;
    }
};