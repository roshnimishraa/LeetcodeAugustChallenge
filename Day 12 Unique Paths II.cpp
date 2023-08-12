Problem Link : https://leetcode.com/problems/unique-paths-ii/

Brute Force : Recursion(TLE) 
 TC:O(2)^m*n  m = row, n=col 

Approach -> Recursion + Memoization = Dynamic Programming 
Time Complexity : O( M X N )
Space Complexity : O(n)
  
class Solution {
         int t[101][101];
    int helper(vector<vector<int>> &grid,int i,int j)
    {

//         row size 
    int m = grid.size();
//     col size
    int n=grid[0].size();
        
       // corner case array out of bound 
// robot can move to 0 cell and 1 is obstacle
    if(i<0 || i>= m || j<0 || j>=n || grid[i][j] ==1){
        return 0;
    }  
//   if ans is calculated for the cell 
    if(t[i][j] != -1) {
        return t[i][j];
    }
        
//    grid reach to the destination 
// eg. for 3*3 matrix end(2,2)
    if(i==m-1 && j==n-1){ 
        return 1;
    } 
//  recursive call for right and down move 
int right = helper(grid,i,j+1);
int down = helper(grid,i+1,j);
    
//   return no of ways robot can react to destination
    return t[i][j] = right+down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
    
// m=row n=col 
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
//         memoization intialization 
memset(t,-1,sizeof(t));
        return helper(obstacleGrid,0,0);
    }
};
