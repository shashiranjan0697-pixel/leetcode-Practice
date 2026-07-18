class Solution {
public:
    typedef pair<int,int> pp;

    struct cmp {
        bool operator()( pair<pp,int>& a, pair<pp,int>& b) {
            return a.second > b.second;
        }
    };

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ans){
        priority_queue< pair<pp,int>, vector< pair<pp,int> >, cmp > pq;
        int n = heights.size();
        int m = heights[0].size();

        pq.push({{0,0},0});
        ans[0][0] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int i=top.first.first, j=top.first.second;
            int eff = top.second;
            
            if(i<n-1){
                int currEff = abs(heights[i+1][j] - heights[i][j]);
                int resEff = max(eff, currEff);
                if(resEff < ans[i+1][j]) {
                    ans[i+1][j] = resEff;
                    pq.push({{i+1,j}, resEff});
                }
            }
            if(j<m-1){
                int currEff = abs(heights[i][j+1] - heights[i][j]);
                int resEff = max(eff, currEff);
                if(resEff < ans[i][j+1]) {
                    pq.push({{i,j+1},resEff});
                    ans[i][j+1]=resEff;
                }
            }
            if(i>0){
                int currEff = abs(heights[i-1][j] - heights[i][j]);
                int resEff = max(eff, currEff);
                if(resEff < ans[i-1][j]) {
                    pq.push({{i-1,j},resEff});
                    ans[i-1][j]=resEff;
                }
            }
            if(j>0){
                int currEff = abs(heights[i][j-1] - heights[i][j]);
                int resEff = max(eff, currEff);
                if(resEff < ans[i][j-1]) {
                    pq.push({{i,j-1},resEff});
                    ans[i][j-1]=resEff;
                }
            }

        }

    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans(n, vector<int> (m, INT_MAX));
        dfs(heights, ans);
    return ans[n-1][m-1];
    }
};