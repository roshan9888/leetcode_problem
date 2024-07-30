class Solution {
public:
    // double solve(double x,int n){
    //     if(n==0) return 1;
    //     return x*solve(x,n-1);
    // }
    double solve(double x, long long n) {
        if (n == 0) return 1.0;
        double half = solve(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        if(n==INT_MAX) return (x==1) ? 1 : (x==-1) ? -1 : 0;
        if(n==INT_MIN) return (x==1 || x==-1) ? 1 : 0;
        double num=1;
        if(n>=0){
            num=solve(x,n);
        }
        else{
            n=-n;
            num=solve(x,n);
            num=1.0/num;
        }
        return num;
    }
};