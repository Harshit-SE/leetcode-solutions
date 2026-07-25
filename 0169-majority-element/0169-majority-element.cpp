class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 2;   // integer division is enough
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for(int i = 0; i < n; i++) {
            if(mp[nums[i]] > threshold) {   // strictly greater
                return nums[i];
            }
        }
        return -1;  // should never happen if majority element guaranteed
    }
};
