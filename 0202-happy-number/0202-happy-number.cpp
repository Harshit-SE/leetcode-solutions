class Solution {
public:
    int getnext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int,int> mp;  // store frequency of numbers

        while (n != 1) {
            if (mp[n] > 0) {   // if already seen → cycle
                return false;
            }
            mp[n]++;           // mark this number as seen
            n = getnext(n);    // move to next number
        }
        return true;           // reached 1 → happy number
    }
};
