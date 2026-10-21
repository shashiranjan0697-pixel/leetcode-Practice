class Solution {
public:
    double average(vector<int>& salary) {
        double totalSalary = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto ele : salary){
            totalSalary += ele;
            maxi = max(maxi, ele);
            mini = min(mini, ele);
        }
        totalSalary -= (maxi + mini);
        totalSalary/=salary.size()-2;
    return totalSalary;
    }
};