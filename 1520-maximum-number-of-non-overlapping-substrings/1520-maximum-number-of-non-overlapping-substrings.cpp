class Solution {
public:

    void fillSubstring(string s,
                       unordered_map<char, int> first,
                       unordered_map<char, int> second,
                       vector<pair<int, int>>& subs) {

        for(char ele = 'a'; ele <= 'z'; ele++) {

            if(first.find(ele) == first.end())
                continue;

            int l = first[ele];
            int r = second[ele];

            bool valid = true;

            for(int i = l; i <= r; i++) {

                // This character started before our substring
                if(first[s[i]] < l) {
                    valid = false;
                    break;
                }

                // We must include all occurrences of this character
                r = max(r, second[s[i]]);
            }

            if(valid) {
                subs.push_back({l, r});
            }
        }
    }

    vector<string> maxNumOfSubstrings(string s) {

        int n = s.length();

        unordered_map<char, int> first, last;
        vector<pair<int, int>> subs;

        // First occurrence
        for(int i = 0; i < n; i++) {
            if(first.find(s[i]) == first.end()) {
                first[s[i]] = i;
            }
        }

        // Last occurrence
        for(int i = n - 1; i >= 0; i--) {
            if(last.find(s[i]) == last.end()) {
                last[s[i]] = i;
            }
        }

        // Generate valid substrings
        fillSubstring(s, first, last, subs);

        // Sort by ending position
        sort(subs.begin(), subs.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int prevEnd = -1;

        // Greedily select non-overlapping intervals
        for(auto ele : subs) {

            int start = ele.first;
            int end = ele.second;

            if(start > prevEnd) {

                ans.push_back(
                    s.substr(start, end - start + 1)
                );

                prevEnd = end;
            }
        }

        return ans;
    }
};