class Solution {
public:

    int binary(vector<int>& arr2, int tar) {
        int l = 0, r = arr2.size();

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(arr2[mid] < tar)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int count = 0;

        for(int i = 0; i < arr1.size(); i++) {

            int idx = binary(arr2, arr1[i] - d);

            if(idx == arr2.size() || arr2[idx] > arr1[i] + d)
                count++;
        }

        return count;
    }
};