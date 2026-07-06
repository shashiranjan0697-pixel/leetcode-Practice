class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        
        sort (arr.begin(), arr.end(), [] (vector<int>&a, vector<int>&b){
            return   (a[0]==b[0])  ? a[1]>b[1] :  a[0]<b[0];
        } );
        int count = 0;
        int end = arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(arr[i][1]<=end){
                count++;
                continue;
            }
            else end = arr[i][1];
        }
        
    return arr.size()-count;
    }
};