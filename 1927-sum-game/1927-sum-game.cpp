class Solution {
public:
    bool sumGame(string nums) {
        int n = nums.length();
        int l = 0, r = 0, lq = 0, rq = 0;
        for(int i=0; i<n;i++){
            
            if(i < n/2) {
                if(nums[i] == '?') lq++;
                else l += nums[i] - '0';
            }
            else {
                if(nums[i] == '?') rq++;
                else r += nums[i] - '0';
            }
        }
        if((rq + lq) % 2 == 1) return true;
        if( (l-r) == (9*((rq-lq)/2))  ) return false;
        

    return true;
    }
};