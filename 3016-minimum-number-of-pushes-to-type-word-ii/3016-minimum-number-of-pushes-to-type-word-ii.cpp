class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> freq, mp;
        map<int, vector<char>, greater<int>> om;
        int cost = 1;
        for(auto ele : word){
            freq[ele]++;
        }

        for(auto ele : freq){
            int f = ele.second, ch=ele.first;
            om[f].push_back(ch);
        }

        for(auto ele : om){
            for(auto c : ele.second ){
                mp.insert({c, cost});
                if(mp.size()%8==0) cost++;
            }
            
        }
        int count =0;
        for(auto ele : word){
            count+=mp[ele];
        }
    return count;
    }
};