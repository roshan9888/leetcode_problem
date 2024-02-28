   
class Solution {
 
public:
//     static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
//     return a.second > b.second; // Compare second element of pairs in descending order
// }
    bool isIdealPermutation(vector<int>& A) {
        //brute force
        // int global=0;
        // int local=0;
        // int n=nums.size();
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         cout<<nums[i]<<"->"<<nums[j]<<endl;
        //         if(i<j && j<n && i!=j && nums[i]>nums[j]){
        //             global++;
        //             cout<<"global"<<global<<endl;
        //         }
        //     }
        // }
        // for (int i = 0; i < n - 1; i++) {
        //     if (nums[i] > nums[i + 1]) {
        //         local++;
        //     }
        // }
        // return global==local ? true :false;

        //time complexity O(n^2 + n)

        //optimal solution
        // unordered_map<int,int>myMap;
        // for(int i=0;i<nums.size();i++){
        //     myMap[nums[i]]=i;
        // }

        // sort(myMap.begin(),myMap.end(),cmp);
        
        // auto it = myMap.begin();
        // int num1=it.first;
        // int i=it.second;
        // int global=0;
        // int local=0;
        // if (it != myMap.end()) {
        //     ++it; // Move to the second element
        // }
        // for (; it != myMap.end(); ++it) {
        //     int i=1;
        //     if(num1>it.first && i<it.second && it.second<n){
        //         global=n-i-1;
        //     }
        //     i++;
        //     num1=it.first;
        //     i=it.second;
        // }

        // for (int i = 0; i < n - 1; i++) {
        //     if (nums[i] > nums[i + 1]) {
        //         local++;
        //     }
        // }
        // return global==local ? true :false;  
        int cmax = 0, n = A.size();
        for (int i = 0; i < n - 2; ++i) {
            cmax = max(cmax, A[i]);
            if (cmax > A[i + 2]) return false;
        }
        return true;
    }
};