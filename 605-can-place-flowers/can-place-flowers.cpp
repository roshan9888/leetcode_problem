class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size();
        if(n==0) return true;
        if(s==1 && flowerbed[0]==0 && n==1) return true;
        if(flowerbed[0]==0 && flowerbed[1]==0){
           flowerbed[0]=1;
           n--;
           if(n==0) return true;
        }
        if(flowerbed[s-1]==0 && flowerbed[s-2]==0){
           flowerbed[s-1]=1;
           n--;
           if(n==0) return true;
        }
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i]==0 && flowerbed[i-1]!=1 &&flowerbed[i+1]!=1){
                n--;
                if(n==0) return true;
                flowerbed[i]=1;
            }
        }
        
        return n==0 ? true : false;
    }
};