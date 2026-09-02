class Solution {
public:

    int bfs(vector<vector<int>>& grid, queue<pair<int, int> >& q, int& fresh) {

        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        while(!q.empty()){
            int s = q.size();
            while(s>0){
                auto front = q.front();
                int i = front.first;
                int j = front.second;
                q.pop();
                s--;
                // top
                if(i>0 && grid[i-1][j]==1) {
                    grid[i-1][j]=2;
                    q.push({i-1, j});
                    fresh--;
                }
                // down
                if(i<n-1 && grid[i+1][j]==1) {
                    grid[i+1][j]=2;
                    q.push({i+1, j});
                    fresh--;
                }
                // right
                if(j<m-1 && grid[i][j+1]==1) {
                    grid[i][j+1]=2;
                    q.push({i, j+1});
                    fresh--;
                }
                // left
                if(j>0 && grid[i][j-1]==1) {
                    grid[i][j-1]=2;
                    q.push({i, j-1});
                    fresh--;
                }
            }
        if(!q.empty()) time++;
        }
    return fresh == 0 ? time : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int> > q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
    return bfs(grid, q, fresh);
    }
};