class Solution {
public:
    long long Power(long long N,long long R){
        if(R==0) return 1;
        if(R==1) return (N%1000000007);

        long long ans=1;
        long long know=(Power(N,R/2)%1000000007);
        if(R%2){
            ans=(ans*N)%1000000007;
        }
        return (ans*((know*know)%1000000007))%1000000007;
    }
    int countGoodNumbers(long long n) {
        if(n%2){
            return (5*Power(20,n/2))%1000000007;
        }
        return Power(20,n/2);
    }
};