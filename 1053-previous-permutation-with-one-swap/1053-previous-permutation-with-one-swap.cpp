class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int breakingPoint = -1;
        for(int i=n-2; i>=0;i--){
            if(arr[i] > arr[i+1]){
                breakingPoint = i;
                break;
            }
        }

        if(breakingPoint == -1) return arr;

        int reqIdx = -1;
        for(int i=n-1; i>breakingPoint;i--){
            if(arr[i] < arr[breakingPoint]){
                if(reqIdx != -1 && arr[i] >= arr[reqIdx]) {
                    reqIdx = i;
                }
                else if(reqIdx == -1) {
                    reqIdx = i;
                }
            }
        }
        swap(arr[breakingPoint], arr[reqIdx] );

    return arr;
    }
};