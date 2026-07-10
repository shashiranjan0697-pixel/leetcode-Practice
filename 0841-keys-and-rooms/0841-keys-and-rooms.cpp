class Solution {
public:
    void bfs(vector<vector<int>>& rooms,int i, unordered_set<int>& visited){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int m = rooms[i].size();
            for(int j=0;j<m;j++){
                int key = rooms[i][j];
                if(!visited.count(key)){
                    visited.insert(key);
                    q.push(key);
                }
            }
            q.pop();
            i = q.front();
        }
    }


    void dfs(vector<vector<int>>& rooms,int i, unordered_set<int>& visited){
            visited.insert(i);
            int m = rooms[i].size();
            for(int j=0;j<m;j++){
                int key = rooms[i][j];
                if(!visited.count(key)){
                    dfs(rooms, key, visited);
                }
            }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;
        visited.insert(0);
        dfs(rooms, 0, visited);
    return visited.size()==n;
    }
};