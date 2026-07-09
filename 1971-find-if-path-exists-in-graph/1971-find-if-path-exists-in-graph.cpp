class Solution {
public:
    bool bfs( unordered_map<int, vector<int>>& mp, int s, int d, int n ){
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            vector<int> temp = mp[s];
            int m = temp.size();
            for(int i=0;i<m;i++){
                if(visited[d]) return true;
                if(!visited[temp[i]]){
                    q.push(temp[i]);
                    visited[temp[i]]=true;
                }
            }
            q.pop();
            s=q.front();    
        }
    return false;
    }

   void adjacencyListformation(vector<vector<int>>& edges,
                            unordered_map<int, vector<int>>& mp) {
        for (auto &edge : edges) {
            int src = edge[0];
            int dest = edge[1];

            mp[src].push_back(dest);
            mp[dest].push_back(src);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>mp;
        adjacencyListformation(edges, mp);
        if(n==1) return true;
    return bfs(mp, source, destination, n);
    }
};