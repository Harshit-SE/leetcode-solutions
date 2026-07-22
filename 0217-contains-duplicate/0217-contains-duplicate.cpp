class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // make duplicates adjacent
        for(int i=0; i < nums.size() - 1; i++){
            if((nums[i] ^ nums[i+1]) == 0){
                return true;
            }
        }
        return false;   // proper bool return
    }
};
