class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();

        int i = 0;
        int j = 1;

        int left = -1;
        int right = -1;

        // Find the first and last places
        // where the array is decreasing
        while (j < n) {

            if (nums[i] > nums[j]) {

                if (left == -1) {
                    left = i;
                }

                right = j;
            }

            i++;
            j++;
        }

        // Already sorted
        if (left == -1) {
            return 0;
        }

        // Find minimum and maximum
        // inside the unsorted part
        int mini = nums[left];
        int maxi = nums[left];

        for (int k = left; k <= right; k++) {
            mini = min(mini, nums[k]);
            maxi = max(maxi, nums[k]);
        }

        // Expand left if needed
        while (left > 0 && nums[left - 1] > mini) {
            left--;
        }

        // Expand right if needed
        while (right < n - 1 && nums[right + 1] < maxi) {
            right++;
        }

        return right - left + 1;
    }
};