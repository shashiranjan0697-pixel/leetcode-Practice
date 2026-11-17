class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = -1;
        int secondLargest = -1;

        for(int i = 0; i < nums.size(); i++) {

            if(largest == -1 || nums[i] > nums[largest]) {
                secondLargest = (largest == -1) ? -1 : nums[largest];
                largest = i;
            }
            else if(secondLargest == -1 || nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }
        cout<<largest<< " , " << secondLargest;
        if(secondLargest*2 <= nums[largest]) 
            return largest;

    return -1;
    }
};