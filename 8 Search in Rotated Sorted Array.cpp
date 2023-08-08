Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/
Brute Force : Linear Search 
TC : O(n) 
  SC : O(1) 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int res=-1;
    for(int i=0;i<n;i++){
        if(nums[i%n] == target){
            res= i;
        }
    }
        return res;
    }
};

------------------------------------------------------------------------------------------------------------------------------------------
  Efficient Approach : Binary Search 
TC : O(log n) 
SC : O(1) 
Approach : Either left or right half is sorted 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //binary search 
        int low = 0;
        int n=nums.size();
        int high = n-1;
  while(low <= high){
  int mid = (low + high)/2;
  if(nums[mid] == target){
            return mid;
        }
if(nums[low] <= nums[mid]){
 if(nums[low] <= target && target <= nums[mid]){
    high = mid-1;
  }
 else {
   low = mid+1;
 }
 }
else {
 if(nums[mid] <= target && target <= nums[high]){
 low = mid+1;
  }
    else {
high = mid -1 ;
}
}
}
 return -1;
    }
};
