
Approach : Recusion + Memoization = Dynamic Programming 

class Solution {
    
public:
    int t[301][50001];
    int solve(int index,vector<int> coins,int amount)
    {
        if(amount == 0) return 1;
        int n= coins.size();
        if(index == n) return 0;
    
        if(t[index][amount] != -1) return t[index][amount];
// skip 
        if(coins[index] > amount) {
//      skip
   return t[index][amount]=solve(index+1,coins,amount);
        }
//    take 
  int take =  solve(index,coins,amount-coins[index]);
//     skip 
int skip =    solve(index+1,coins,amount);
        return t[index][amount] = take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
     memset(t,-1,sizeof(t));
        return solve(0,coins,amount);
    }
};
