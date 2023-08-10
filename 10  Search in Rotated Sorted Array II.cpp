Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Approach : Binary Search 
Duplicacy condition 
arr[low] == arr[mid] && arr[mid] == arr[high]

Eg. arr = [ 4 5 5 5 1 3 5 5 6 ]  n=9 target = 5
1. mid= 1 case 4 target > mid && target <= high 
     low=mid+1 
new arr = [3 5 5 6] mid= 5(ind=1) now mid > low   case 3 
         low < target && target <= mid high= mid-1
2. mid = 3  low=mid+1  case 4 
3 mid==target return true 
 
TC : O(log N) average case worst case can be O(N/2)
SC : O(1) 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
    while(low <= high){
        int mid=(low+high)/2;
// case 1
    if(nums[mid] == target){
        return true;
    }
//     case 2:    duplicacy condition
    if(nums[mid] == nums[low] && nums[mid] == nums[high]){
        low++;
        high--;
        continue;
    }
//     case 3
    if(nums[low] <= nums[mid]){
        if(nums[low] <= target && target < nums[mid]){
            high= mid-1;
        }
        else{
            low=mid+1;
        }
    }
// case 4
else {
    if(nums[mid] < target && target <= nums[high]){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
    }
        return false;
    }
};
