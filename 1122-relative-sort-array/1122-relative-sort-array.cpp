class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a1, vector<int>& a2) {
        unordered_map<int, int> mp;
        
        int i=0;
        for(auto ele : a1) mp[ele]++;
        
        for(auto ele : a2) {
            
            if(mp.find(ele)!=mp.end()){
                while(mp[ele] > 0) {
                    a1[i] = ele;
                    mp[ele]--;
                    i++;
                    if(mp[ele] == 0) mp.erase(ele);
                }
            }
        }
        int size = i;
        
        for(auto ele : mp) {
            while(mp[ele.first] > 0) {
                a1[i] = ele.first;
                    mp[ele.first]--;
                    i++;
            }
        }
    sort(a1.begin()+size, a1.end());
    return a1;
    }
};