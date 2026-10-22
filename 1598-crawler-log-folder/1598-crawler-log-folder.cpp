class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int curr = 0;
        for(int i=0; i<n; i++){
            if( logs[i]=="../") {
                if(curr>0)  curr--;
            }
            else if(logs[i]=="./") continue;
            else{
                curr++;
            }
        cout<<curr;
        }
    return curr;
    }
};