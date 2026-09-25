class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> sample = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> st;
        for(auto ele : words){
            string temp = "";
            for(auto c : ele){
                temp += sample[c - 'a'];
            }
        st.insert(temp);
        }
    return st.size();
    }
};