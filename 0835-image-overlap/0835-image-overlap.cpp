class Solution {
public:

    typedef pair<int,int> pp;

    struct Hash {
        size_t operator()(const pp& p) const {
            return p.first ^ p.second;
        }
    };
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();

        vector<pp> im1;
        vector<pp> im2;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(img1[i][j] == 1) im1.push_back({i,j});
                if(img2[i][j] == 1) im2.push_back({i,j});
            }
        }

        unordered_map<pp,int, Hash> mp;

        for(auto &ele : im1) {
            for (auto &e : im2) {
                int x1 = ele.first, y1=ele.second, x2 = e.first, y2=e.second;
                int x3 = x2-x1, y3 = y2-y1;
                mp[{x3,y3}]++;
            }
        }

        int ans = 0;

        for(auto &ele : mp) {
            ans = max(ans, ele.second);
        }

    return ans;
    }
};