class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        vector<int> ans;
        for(auto &p : mp) {
            if(p.second > threshold) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
