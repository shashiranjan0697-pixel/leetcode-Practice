class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;

        vector<int> freq(26, 0);

        // Count characters in the first string
        for(char c : words[0]) {
            freq[c - 'a']++;
        }

        // Process remaining strings
        for(int i = 1; i < words.size(); i++) {
            vector<int> curr(26, 0);

            for(char c : words[i]) {
                curr[c - 'a']++;
            }

            // Keep the minimum frequency across strings
            for(int j = 0; j < 26; j++) {
                freq[j] = min(freq[j], curr[j]);
            }
        }

        // Add common characters, including duplicates
        for(int i = 0; i < 26; i++) {
            while(freq[i]--) {
                ans.push_back(string(1, 'a' + i));
            }
        }

        return ans;
    }
};