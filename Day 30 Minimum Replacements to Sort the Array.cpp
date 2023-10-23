/* ALGORITHM : Using Greedy Approach - T.C : O(n) , S.C : O(1)
1. Traverse from n-2 to 0 index
2. if nums[i] <= nums[i+1] then continue
 else 
     we need divide into parts in minimum operation
     parts = nums[i]/nums[i+1]     
     eg. nums[]= [1,2,11,3] 11/3 = 3 parts parts = 4 
     if nums[i] % nums[i+1] != 0 then part = parts + 1
3. Find number of Operation 
    operations += parts - 1
4. Now change nums[i] from 11 to 3,4
nums[i] = nums[i]/parts 
5. return operations 
*/

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
int n = nums.size();
long long operation = 0;
for(int i=n-2;i>=0;i--){
    if(nums[i] <= nums[i+1]) // Ascending order no change 
  {
 continue;
  } 
  
int parts = nums[i]/nums[i+1];
    if(nums[i] % nums[i+1] != 0)
        parts += 1;

    nums[i]= nums[i]/parts;
      operation += parts-1;
}
 return operation;
    }
};
