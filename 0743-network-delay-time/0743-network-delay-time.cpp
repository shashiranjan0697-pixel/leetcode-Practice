class Solution {
public:
    struct cmp {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        }
    };

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
        unordered_map<int, vector<pair<int,int> > > mp;
        for(auto ele : times){
            int src = ele[0], dest = ele[1], wet = ele[2];
            mp[src].push_back({dest, wet});
            // mp[dest].push_back({src, wet});
        }

        vector<int>time(n+1, INT_MAX);
        time[0]=-1;
        bfs(mp, time, k);
        int ans=0;
        for(auto x : time) ans = max(ans, x);
        
    return ans == INT_MAX ? -1 : ans;
    }
};