class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {

        int n = s.length();

        vector<vector<int>> ans;

        int start = 0;

        for(int i=0; i<n; i++) {

            if(s[i]==s[start]) continue;

            else{
                int size = i - start;
                if(size >= 3) ans.push_back({start,i-1});

                start = i;
            }
        }

        if(n - start >= 3) ans.push_back({start,n-1});

    return ans;
    }
};