class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;   // key = number, value = frequency
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]>1){   // check when frequency becomes 2
                return nums[i];
            }
        }
        return -1;  // in case no duplicate found
    }
};
