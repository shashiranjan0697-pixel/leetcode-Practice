class Solution {
public:
    void bfs (vector<vector<int>>& isConnected, int i, vector<bool> &visited){
        queue<int> q;
        int n = isConnected.size();
        q.push(i);
        while(!q.empty()){
            for(int j=0;j<n;j++){
                if(!visited[j] && isConnected[i][j]==1){
                    visited[j]=true;
                    q.push(j);  
                }
            }
            q.pop();
            i=q.front();
        }
    }

    void dfs(vector<vector<int>>& isConnected, int i, vector<bool> &visited){
        int n = isConnected.size();
        visited[i]=true;
        for(int j=0;j<n;j++){
            if(!visited[j] && isConnected[i][j]==1){
                    dfs(isConnected, j, visited);  
                }
        }

    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i]=true;
                count++;
                dfs(isConnected,i,  visited);
            }
        }
    return count;
    }
};