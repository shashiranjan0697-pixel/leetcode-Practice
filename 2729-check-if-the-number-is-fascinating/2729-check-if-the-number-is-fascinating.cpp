class Solution {
public:
    unordered_set<int> st;
    void help (int n) {
        string s = "";
        while(n>0){
            int temp = n%10;
            if(temp != 0)
                st.insert(temp);
            n/=10;
        }
    }
    bool isFascinating(int n) {
        st.clear();

        help(n);

        if(n*2 < 1000)
            help(n*2);

        if(n*3 < 1000)
            help(n*3);

    return st.size() == 9;
    }
};