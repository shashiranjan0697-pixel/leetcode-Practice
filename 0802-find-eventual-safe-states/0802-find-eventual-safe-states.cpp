class Solution {
public:
    void bfs (vector<int>& ans, unordered_map<int,vector<int> >& mp, vector<int>& inDeg){
        queue<int> q;

        for(int i=0;i<inDeg.size();i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto e : mp[front]){
                inDeg[e]--;
                if(inDeg[e]==0 ){
                    q.push(e);
                }
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<int> inDeg(n,0);
        unordered_map<int,vector<int> > mp;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int key = graph[i][j];
                mp[key].push_back(i);

                inDeg[i]++;
            }
        }
        bfs(ans, mp, inDeg);
        sort(ans.begin(), ans.end());
    return ans;
    }
};