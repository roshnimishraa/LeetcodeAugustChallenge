Brute Force : Recursion - Find all possible "p" pairs 

Efficient Approach : Binary Search on Answer 
Eg. arr = [10, 1, 2, 7, 1, 3] p=2
sol 
  ans =0;
1. sort [1,1,2,3,7,10]    low =0  high = 10 - 1=9
2. calculate mid = 4 check pairDiff <= 4
  (1,1) ,(2,3) , (7,10) 
  3 pairs > 2 ans = 3
Check for min value 
3.  low = 0 high =3 mid = 1 
  pairDiff (1,1,) , (2,3)  
  2 pairs <= 2  ans = 2 
Check for min value 
4. low=0 high=0 mid=0 
  (1,1) 1<2 not accepted Check for greater value 
5. low = 1 high 0  since low > high = stop 
  ans = low 
o/p: 1 min pair difference
  
isValid(arr,mid,p)  //p=no. of pairs
1. i -> 0 to n-1
2. PairDiff <= mid 
       count++ 
       check for next pair i += 2
  if PairDiff > mid i++ // move by one
3. return true if count >= p

minMaxArr(nums,p)
1. Sort the array 
2. low = 0 and 
  high = arr[n-1]-arr[0] (max difference)
3. find mid and check (isValid) how many pairs difference <= mid
      if isValid true then search min value of mid of pairs <= mid 

TC : O(N * LOG M)
SC : O(1) 

class Solution {
    bool isValid(vector<int>& nums,int mid,int p){
      int i=0;
        int n=nums.size();
        int countPairs=0;
        while(i<n-1){
        
            if((nums[i+1] - nums[i]) <= mid){
                countPairs++;
                i+=2; // pairing
            }
            else {
                i++;
            }
        }
        return countPairs >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0;
        int n=nums.size();
        int high=nums[n-1]-nums[0];
        int ans=0;
    while(low <= high){
        int mid=(low+high)/2;
        
        if(isValid(nums,mid,p)){
            ans = mid;
            high=mid-1;
        }
        else{
            low = mid+1;
        }
    
    }
        return ans;
    }
};
