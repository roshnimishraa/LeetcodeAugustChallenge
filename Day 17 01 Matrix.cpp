Approach : BFS Traversal 
 to find shortest path in graph, 2-d matrix , BFS must come to your mind first

TC : O(M*N) Since we update the 1 with smallest distance, we don't get to visit that again and hence
	every cell gets added to queue only once.

  
  
  class Solution {
    int x[4]= {0,0,1,-1};
    int y[4]={-1,1,0,0};

    vector<vector<int>> directions{{0,-1},{0,1},{1,0},{-1,0}};
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); //row
        int n=mat[0].size(); //col
        queue<pair<int,int>> que;
        vector<vector<int>> result(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
for(int j=0;j<n;j++)
{
    if(mat[i][j] == 0){
        result[i][j]=0;
        que.push({i,j}); //store coordinate which is 0
    }
}
 }
        while(!que.empty()){
            pair<int,int> p=que.front();
            que.pop();
            int i = p.first;
            int j=p.second;
            
        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
    //isValid 
      if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && result[new_i][new_j] == -1) {
                    result[new_i][new_j] = result[i][j] + 1;
                    que.push({new_i, new_j});
      }
        }
        }
        return result;
    }
};
