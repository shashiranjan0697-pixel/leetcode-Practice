class Solution {
public:
    struct cmp {
        bool operator() (pair<int,double> &a, pair<int,double> &b){
            return a.second < b.second;
        }
    };

    void bfs(unordered_map<int, vector<pair<int,double> > >& mp, vector<double>& prob, int node){
        priority_queue<pair<int,double>, vector<pair<int,double> >, cmp > pq;
        pq.push({node, 1});
        prob[node]=1;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int src = top.first;
            double wt = top.second;

            if(wt < prob[src]) continue;

            for(auto ele : mp[src]){
                int d = ele.first;      // destination
                double p = ele.second;    // probability

                if(wt*p > prob[d]){
                    prob[d] = wt*p;
                    pq.push({d, wt*p});
                }
            }

        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int,double> > > mp;
        int m = edges.size();
        for(int i=0;i<m;i++){
            int src = edges[i][0], dest = edges[i][1];
            mp[src].push_back({dest, succProb[i]});
            mp[dest].push_back({src, succProb[i]});
        }
        vector<double> prob(n, 0);
        prob[start_node] = 1;
        bfs(mp, prob, start_node);
    return prob[end_node];
    }
};