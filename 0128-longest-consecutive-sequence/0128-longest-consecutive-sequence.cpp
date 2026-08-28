class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int curr = 1;
        int longest = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i - 1]) {
                // Duplicate, ignore it
                continue;
            }

            if(nums[i] == nums[i - 1] + 1) {
                // Consecutive
                curr++;
            }
            else {
                // New sequence starts
                curr = 1;
            }

            longest = max(longest, curr);
        }

        return longest;
    }
};