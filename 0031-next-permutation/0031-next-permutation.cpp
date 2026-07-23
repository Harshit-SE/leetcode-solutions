class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int small = -1;

        // Find the first decreasing element from the end
        for(int i = n - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]){
                small = i - 1;
                break;
            }
        }

        if(small == -1){ // already the largest permutation
            reverse(nums.begin(), nums.end());
            return;
        }

        int greater = -1;
        // Find the element just larger than nums[small]
        for(int i = n - 1; i > small; i--){
            if(nums[i] > nums[small]){
                greater = i;
                break;
            }
        }

        swap(nums[small], nums[greater]);
        reverse(nums.begin() + small + 1, nums.end());
    }
};
