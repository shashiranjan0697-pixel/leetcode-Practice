class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i,int j){
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){

            if(j<m-1 && !visited[i][j+1] && grid[i][j+1]=='1') {
                visited[i][j+1]=true;
                q.push({i,j+1});
            }

            if(j>0 && !visited[i][j-1] && grid[i][j-1]=='1') {
                visited[i][j-1]=true;
                q.push({i,j-1});
            }

            if(i<n-1 && !visited[i+1][j] && grid[i+1][j]=='1') {
                visited[i+1][j]=true;
                q.push({i+1,j});
            }

            if(i>0 && !visited[i-1][j] && grid[i-1][j]=='1') {
                visited[i-1][j]=true;
                q.push({i-1,j});
            }
            

        q.pop();
        if(q.size()==0) break;
        i=q.front().first;
        j=q.front().second;
          
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    visited[i][j] = true;
                    bfs(grid, visited, i,j);
                    count++;
                }
            }
        }
    return count;
    }
};