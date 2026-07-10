class Solution {
public:
    bool ans = true;
    void bfs(vector<vector<int>>& graph, vector<int>& visited, int i){
        queue<int>q;
        q.push(i);
        visited[i] = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop(); 
            for(int ele : graph[front]){
                if (visited[ele]==-1){
                    visited[ele] = 1 - visited[front];
                    q.push(ele);
                }
                else if(visited[ele]==visited[front]){
                    ans = false;
                    return;
                }    
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                bfs(graph, visited, i);
                if(!ans) return ans;  
            }
        }
    return  true;
    }
};