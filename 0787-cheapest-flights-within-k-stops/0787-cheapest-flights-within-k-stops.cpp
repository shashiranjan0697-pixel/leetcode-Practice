class Solution {
public:
    typedef pair<int,int> pp;

    void dfs(unordered_map<int,vector<pp>>& mp, vector<int>& cost, int src, int k){
        priority_queue<pair<int, pp>, vector<pair<int, pp>>, greater<pair<int, pp>> > pq;
        pq.push({0,{src, 0}});
        cost[src]=0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int stop = top.first, s=top.second.first, price=top.second.second;
            if(stop>k) continue;
            for(auto ele : mp[s]){
                int dest = ele.first, wt=ele.second;
                if(cost[dest]> price+wt){
                    cost[dest]=price+wt;
                    pq.push({stop+1, {dest, price+wt}});
                }
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pp>>mp;
        for(auto ele : flights){
            int from=ele[0], to=ele[1], price=ele[2];
            mp[from].push_back({to, price});
        }
        vector<int> cost(n,INT_MAX);
        dfs(mp, cost, src, k);
    return cost[dst]==INT_MAX ? -1 : cost[dst];
    }
};