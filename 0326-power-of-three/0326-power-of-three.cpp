class Solution {
public:
    bool f(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 3 != 0) return false;
        return f(n / 3);
    }

    bool isPowerOfThree(int n) {
        return f(n);
    }
};