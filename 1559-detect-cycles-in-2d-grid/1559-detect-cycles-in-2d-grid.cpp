class Solution {
public:
    using pp = pair<int, int>;
    bool ans = false;
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j ){
        queue< pair<pp, pp> >q;
        int n = grid.size();
        int m = grid[0].size();
        q.push ( { {i,j} , {-1,-1}} );
        visited[i][j] = true;
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            pp curr = front.first;
            pp parent = front.second;

            int x = curr.first;
            int y = curr.second;

            int px = parent.first;
            int py = parent.second;

            // right
            if(y<m-1 && grid[x][y+1]==grid[x][y]){
                if (visited[x][y + 1] && !(px == x && py == y + 1)) {
                    ans = true;
                    return;
                }
                if(!visited[x][y + 1]) {
                    q.push({{x,y+1}, {x,y}});
                    visited[x][y+1] = true;
                }
            }
            // left
            if(y>0 && grid[x][y-1]==grid[x][y]){
                if (visited[x][y - 1] && !(px == x && py == y - 1)) {
                    ans = true;
                    return;
                }
                if(!visited[x][y - 1]) {
                    q.push({{x,y-1}, {x,y}});
                    visited[x][y-1] = true;
                }
            }
            // down
            if(x<n-1 && grid[x+1][y]==grid[x][y]){
                if (visited[x+1][y] && !(px == x+1 && py == y)) {
                    ans = true;
                    return;
                }
                if(!visited[x+1][y]) {
                    q.push({{x+1,y}, {x,y}});
                    visited[x+1][y] = true;
                }
            }

            if(x>0 && grid[x-1][y]==grid[x][y]){
                if (visited[x-1][y] && !(px == x-1 && py == y)) {
                    ans = true;
                    return;
                }
                if(!visited[x-1][y]) {
                    q.push({{x-1,y}, {x,y}});
                    visited[x-1][y] = true;
                }
            }
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    bfs(grid, visited, i, j);
                    if(ans) return ans;
                }
            }
        }
    return false;
    }
};