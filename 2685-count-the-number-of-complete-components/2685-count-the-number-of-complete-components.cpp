class Solution {
public:
    void dfs(int i, vector<bool>& visited, unordered_map<int, vector<int>>& mp, int &v, int &e){
        visited[i]=true;
        v++;
        e+=mp[i].size();
        for(auto ele : mp[i]){
            if(!visited[ele]){
                dfs(ele, visited, mp, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        vector<bool>visited(n, false);
        int count = 0;
        for(auto ele : edges){
            int x = ele[0], y = ele[1];
            mp[x].push_back(y);
            mp[y].push_back(x);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                int v = 0;
                int e = 0;
                dfs(i, visited, mp, v, e);
                e/=2;
                if( e== (v*(v-1)/2)) count++;
            }
        }
    return count;
    }
};