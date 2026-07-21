class Solution {
public:
    using pp = pair<int,int>;

    int bfs(unordered_map<int,vector<pp> >& mp, vector<bool>& visited){
        priority_queue< pair<int, pp>, vector<pair<int, pp>>, greater<pair<int, pp>> > pq;
        int cost = 0;
        pq.push({0,{0, -1}});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int wt = top.first, node = top.second.first, parent = top.second.second; 
            if(visited[node]) continue;
            cost+=wt;
            visited[node]= true;
            for(auto ele : mp[node]){
                int dest = ele.first, dis=ele.second;
                if(!visited[dest]) pq.push({dis, {dest, parent}}) ;
            }
        }
    return cost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<pp> >mp;   
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                mp[i].push_back({j, dist});
            }
        }
        vector<bool> visited(n,false);
    return bfs(mp, visited);
    }
};