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
        int slow = n;
        int fast = n;
        do {
            slow = getnext(slow);                 // move slow one step
            fast = getnext(getnext(fast));        // move fast two steps
        } while (slow != fast);

        return slow == 1; // if they meet at 1 → happy
    }
};
