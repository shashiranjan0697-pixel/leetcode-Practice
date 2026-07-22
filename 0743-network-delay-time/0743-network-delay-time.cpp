class Solution {
public:
    struct cmp {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        }
    };
// Dijkstra’s algorithm
    void bfs (unordered_map<int, vector<pair<int,int> > >& mp, vector<int>& time, int k){
        priority_queue<pair<int,int>,
                    vector<pair<int,int>>, cmp> pq;
        pq.push({k,0});
        time[k]=0;
        while(!pq.empty()){
            auto top = pq.top();
            int src = top.first;
            int wt = top.second;
            pq.pop();
            if(wt > time[src]) continue;
            for(auto ele : mp[src]){
                int d = ele.first;      // destination
                int t = ele.second;    // weight
                
                if(time[d] > wt+t){
                    time[d] = wt+t;
                    pq.push({d, wt+t});
                }
            }
        }    
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Bellman-Ford Algorithm

        vector<int>res(n+1, INT_MAX);
        res[k]=0;
        for(int i=1;i<n;i++){
            for(auto ele : times){
                int src = ele[0], dest=ele[1], wt=ele[2];

                if(res[src]!=INT_MAX && res[src]+wt < res[dest]) res[dest]=res[src]+wt;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans = max(ans, res[i]);
        
    return ans == INT_MAX ? -1 : ans;
    }
};