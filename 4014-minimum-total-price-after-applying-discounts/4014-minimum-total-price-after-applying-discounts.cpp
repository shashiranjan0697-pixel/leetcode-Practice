class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

        int n = prices.size();
        int m = discounts.size();

        sort(prices.begin(), prices.end(), [](const int &a, const int &b) {
            return a > b;
        });

        sort(discounts.begin(), discounts.end(), [](const int &a, const int &b) {
            return a > b;
        });
        cout<<prices[0]<<" "<<discounts[0];
        double totalPrice = 0;
        for(int i=0; i<n; i++) {
            if(i<m){
                double temp = (prices[i] * (100 - discounts[i])) / 100.0;
                totalPrice += temp;
            }
            else totalPrice += prices[i];
        }
    return totalPrice;
    }
};