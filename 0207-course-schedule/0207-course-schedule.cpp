class Solution {
public:
    // kahn's Algorithm

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
        bool ans = true;

    void dfs(unordered_map<int,vector<int> >& mp, vector<bool>& visited, vector<bool>& path, int i){
        visited[i] = true;
        path[i] = true;
        for(auto ele : mp[i]){
            if(path[ele]){
                ans = false;
                return;
            }
            
            if(!visited[ele])  dfs(mp, visited, path, ele);    
            
        }
        path[i] = false;
    }

    bool canFinish(int n, vector<vector<int>>& arr) {
        // bfs sol
        // vector<int> ans;
        vector<int> inDeg(n,0);
        unordered_map<int,vector<int> > mp;
        for(auto ele : arr){
            int course = ele[0];
            int prereq = ele[1];

            mp[prereq].push_back(course);
            inDeg[course]++;
        } 
        // bfs(ans, mp, inDeg);
    // return n==ans.size();

    // DFS solution 
        // ans = true;
        vector<bool> visited(n,false);
        vector<bool> path(n,false);
        for(int i=0;i<n;i++ )    dfs(mp, visited, path, i);
    return ans;
    }
};