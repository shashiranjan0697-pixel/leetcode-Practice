class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1){
                    int peri = 4;
                    // top
                    if(i>0 && grid[i-1][j] == 1) peri--;
                    // bottom
                    if(i<n-1 && grid[i+1][j] == 1) peri--;
                    // left
                    if(j>0 && grid[i][j-1] == 1) peri--;
                    // right
                    if(j<m-1 && grid[i][j+1] == 1) peri--;
                
                ans += peri;
                }
            }
        }
    return ans;
    }
};