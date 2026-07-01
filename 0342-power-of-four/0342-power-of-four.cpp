class Solution {
public:
    bool f(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 4 != 0) return false;
        return f(n / 4);
    }
    bool isPowerOfFour(int n) {
        return f(n);
    }
};