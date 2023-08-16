
Efficient Approach:
Pattern : Monotonic Increasing/Decreasing 

Approach-1 (Using Deque) : Monotonic Decreasing Deque

 TC : O(N) , Every element is added(pushed) and popped only once
 SC : O(N) 

Logic :
1. When new element comes nums[i], make space for it (Window Size can not be greater than K) 
2. Now, when nums[i] comes there is no need to keep small elements in that window pop then 
3. now push i in dequeu -> for nums[i]
4. if i>= k-1 then deq.front() is the answer for particular k size window 

Eg. nums[] = [1,3,-1,-3,5,3,6,7]  k=3

dq[] 
ans[] 

i=0 to 2
 dq[] =[1,3,-1]
ans [] = [3]

i= 1 to 3
 dq [3,-1,-3]
ans = [3,3] 

i=2 to 4 
dq = [-1,-3,5]
ans = [3,3,5]

i = 3 to 5 
 dq = [5,3]
ans = [3,3,5,5]

i = 4 to 6
dq = [5,3,6]
ans = [3,3,5,5,6]

i=5 to 7
dq = [6,7]
ans =[3,3,5,5,6,7]


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
          if(n == 0)
            return {}; 
        
    for(int i=0;i<n;i++){
    //1. make space for nums[i] till window size(i-k)
   // jo element push kr rhe h window size me agar uska prev usse small hai 
// deq.front se pop kr do
      //2 3 4 (2 & 3 will pop front)
    while(!dq.empty()  && dq.front() <= i-k){
        
        dq.pop_front();
    }
        
//2. Jo next element agega vo prev wale se big ele to prev ko pop kr dena h
    while(!dq.empty() && nums[i] > nums[dq.back()]){
        dq.pop_back();
    }
//3 push i
  dq.push_back(i);
        
//4. mujhe ek window ke liye max element mil gya 
        if(i>= k-1) {
            ans.push_back(nums[dq.front()]);
        }
    }
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

Better Approach : Using Max heap(Priority Queue ) 
TC : O(N * LOG N) 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
 priority_queue<pair<int,int>> pq;
        vector<int> ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        
    while(!pq.empty() && pq.top().second <= i-k){
        pq.pop();
    }
        //we will always find the max element at top
        pq.push({nums[i],i});
        
        if(i>=k-1){
            ans.push_back(pq.top().first);
        }
    }
        return ans;
    }
};
