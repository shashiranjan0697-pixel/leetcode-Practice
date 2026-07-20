class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m = grid[0].size();
        if(k==0) return grid;
        vector<vector<int>>ans (n, vector<int>(m,0));
        while(k-->0){
            for(int i=0;i<n;i++){
                int prev;
                for(int j=0;j<m;j++){
                   if(i==0 && j==0){
                        ans[i][j]=grid[n-1][m-1];
                   }
                   else if(j==0) ans[i][j] = grid[i-1][m-1];
                   else{
                        ans[i][j] = grid[i][j-1];
                   }
                   
                }
            }
        grid.clear();
        grid=ans;
        }
    return ans;
    }
};