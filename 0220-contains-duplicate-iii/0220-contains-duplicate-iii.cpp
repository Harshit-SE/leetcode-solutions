class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        multiset<long long> st;

        for (int i = 0; i < nums.size(); i++) {

            // Remove elements outside the index window
            if (i > indexDiff) {
                st.erase(st.find((long long)nums[i - indexDiff - 1]));
            }

            long long num = nums[i];

            // First element >= num
            auto it = st.lower_bound(num);

            // Check ceiling
            if (it != st.end() && *it - num <= valueDiff) {
                return true;
            }

            // Check floor
            if (it != st.begin()) {
                auto prevIt = prev(it);

                if (num - *prevIt <= valueDiff) {
                    return true;
                }
            }

            st.insert(num);
        }

        return false;
    }
};