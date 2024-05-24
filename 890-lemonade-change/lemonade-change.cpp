class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int change=0;
        int fives=0,ten=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                fives++;
            }
            else if(bills[i]==10){
                if(fives==0){
                    return false;
                }
                fives--;
                ten++;
            }
            else{
                if(ten>0 && fives>0){
                    ten--;
                    fives--;
                }
                else if(fives>=3){
                    fives-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};