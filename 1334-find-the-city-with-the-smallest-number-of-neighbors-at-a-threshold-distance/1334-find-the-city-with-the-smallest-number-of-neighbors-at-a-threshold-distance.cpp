class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, 10004));

        for(auto ele : edges){
            int from = ele[0], to=ele[1], wt=ele[2];
            adj[from][to] = wt;
            adj[to][from] = wt;
        }
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        for(int p=0;p<n;p++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int dist = adj[i][p] + adj[p][j];
                    adj[i][j] = min(adj[i][j], dist);
                }
            }
        }
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            int cnt = 0;
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if(adj[i][j]<=distanceThreshold) cnt++;
                }
            mp[i]=cnt;
            }
        int ans = -1, sze = n;
        for(auto ele : mp){
            int m = ele.second;
            if(sze>m){
                sze=m;
                ans = ele.first;
            }
            else if(sze==m) ans = max(ans, ele.first);
        }
    return ans;
    }
};