Better Approach Recursion + Memoization 

 TC : O(m * n *N ) 
class Solution {
public:
 int m,n,N;
 int t[101][101][201];
 bool solve(int i,int j,int k,string &s1,string &s2,string &s3)
 {
     if(i==m && j==n && k==N){
         return true;
     }
     if(k >= N){
         return false;
     }
     if(t[i][j][k] != -1){
         return t[i][j][k];
     }
     bool result = false;

     if(s1[i] == s3[k]){
        result= solve(i+1,j,k+1,s1,s2,s3);
     }
   if(result == true) {
       return t[i][j][k] = result;
   }
     if(s2[j] == s3[k]){
        result =solve(i,j+1,k+1,s1,s2,s3);
     }
     return t[i][j][k] = result;
 }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        // initialize
 memset(t,-1,sizeof(t));
return solve(0,0,0,s1,s2,s3);
    }
};
----------------------------------------------------------------------------------------------------------------------------------------------------------
Efficient Appraoch 
 DP 
 2 variable i,j
 k = i+j

 TC : O(m * n) 

 class Solution {
public:
 int m,n,N;
 int t[101][101];
 bool solve(int i,int j,string &s1,string &s2,string &s3)
 {
     if(i==m && j==n && i+j==N){
         return true;
     }
     if(i+j >= N){
         return false;
     }
     if(t[i][j] != -1){
         return t[i][j];
     }
     bool result = false;

     if(s1[i] == s3[i+j]){
        result= solve(i+1,j,s1,s2,s3);
     }
   if(result == true) {
       return t[i][j]= result;
   }
     if(s2[j] == s3[i+j]){
        result =solve(i,j+1,s1,s2,s3);
     }
     return t[i][j] = result;
 }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        // initialize
 memset(t,-1,sizeof(t));
return solve(0,0,s1,s2,s3);
    }
};



 
