class Solution {
public:
    void bfs (vector<int>& ans, unordered_map<int,vector<int> >& mp, vector<int>& inDeg){
        queue<int> q;

        for(int i=0;i<inDeg.size();i++){
            if(inDeg[i]==0){
                q.push(i);
                // visited[i]=true;
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
                    // visited[e] = true;
                }
            }
        }
    }

    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<int> ans;
        vector<int> inDeg(n,0);
        // vector<bool> visited(n, false);
        unordered_map<int,vector<int> > mp;
        for(auto ele : arr){
            int course = ele[0];
            int prereq = ele[1];

            mp[prereq].push_back(course);
            inDeg[course]++;
        }
         
        bfs(ans, mp, inDeg);
    return n==ans.size();
    }
};