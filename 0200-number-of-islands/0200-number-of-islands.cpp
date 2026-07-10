class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i,int j){
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){

        i=q.front().first;
        j=q.front().second;
        q.pop();

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
        }
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i,int j){
        int n = grid.size();
        int m = grid[0].size();
    
        visited[i][j]=true;

            // right check
            if(j<m-1 && !visited[i][j+1] && grid[i][j+1]=='1') {
                dfs(grid, visited, i, j+1);
            }

            // left check
            if(j>0 && !visited[i][j-1] && grid[i][j-1]=='1') {
                dfs(grid, visited, i, j-1);
            }

            // top check
            if(i<n-1 && !visited[i+1][j] && grid[i+1][j]=='1') {
                dfs(grid, visited, i+1, j);
            }

            // bottom check
            if(i>0 && !visited[i-1][j] && grid[i-1][j]=='1') {
                dfs(grid, visited, i-1, j);
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
                    // bfs(grid, visited, i,j);
                    dfs(grid, visited, i,j);
                    count++;
                }
            }
        }
    return count;
    }
};