class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current=0;
        int maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            current+=nums[i];
            maxsum=max(current,maxsum);
            if(current<0){
                current =0;
                
            }
    }
    return maxsum;
    }
};