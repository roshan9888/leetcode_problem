class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countpairs(vector<int>& nums,int low,int mid,int high){
    int count=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && nums[i]>2LL*nums[right]) right++;
        count+=(right-(mid+1));
    }
    return count;
}

int mergeSort(vector<int> &nums, int low, int high) {
    int count=0;
    if (low >= high) return count;
    int mid = (low + high) / 2 ;
    count+=mergeSort(nums, low, mid);  // left half
    count+=mergeSort(nums, mid + 1, high); // right half
    count+=countpairs(nums,low,mid,high);
    merge(nums, low, mid, high);  // merging sorted halves
    return count;
}


    int reversePairs(vector<int>& nums) {
        // brute force
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if((long long)nums[i]>2LL*nums[j]){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //optimal solution using merge sort
        return mergeSort(nums,0,nums.size()-1);
    }
};