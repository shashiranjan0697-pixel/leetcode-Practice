class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> temp;
        int m = searchWord.length();
        int ans = 1;
        string str = "";
        for(int i=0; i<sentence.length(); i++){
            str += sentence[i];
            if(sentence[i] == ' ' || i==sentence.length()-1){
                if(str.substr(0,m) == searchWord){
                    return ans;
                }
                else{
                    str = "";
                    ans++;
                }
            }
        }
    return -1;
    }
};