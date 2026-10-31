class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = 0;

        for(auto &ele : arr)
            total += ele;

        if(total % 3 != 0)
            return false;

        int curr = 0, check = total / 3;
        int count = 0;

        for(int i = 0; i < arr.size() - 1; i++) {
            curr += arr[i];

            if(curr == check) {
                total -= curr;
                curr = 0;
                count++;

                if(count == 2)
                    break;
            }
        }

        return count == 2 && total == check;
    }
};