class Solution {
public:
    void bfs(unordered_map<int,vector<int>>& mp, 
                unordered_set<int>& suspicious, 
                vector<bool>& visited, int src){
        queue<int> q;
        if(!suspicious.count(src)){
            q.push(src);
            visited[src]=true;
        }
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            for(auto &ele : mp[front]){
                if(!visited[ele]){
                    if(suspicious.count(ele)){
                        suspicious.erase(ele);
                    }
                    q.push(ele);
                    visited[ele] = true;
                }
                
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> suspicious;
        unordered_map<int, vector<int>> mp;
        for(auto &ele : invocations){
            mp[ele[0]].push_back(ele[1]);
        }

        queue<int> q;
        q.push(k);
        suspicious.insert(k);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : mp[u]){
                if(!suspicious.count(v)){
                    suspicious.insert(v);
                    q.push(v);
                }
            }
        }

        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious.count(u) && suspicious.count(v)) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
            vector<int> ans;
        for(int i=0;i<n;i++){
            if(!suspicious.count(i)) ans.push_back(i);
        }
    return ans;
    }
};