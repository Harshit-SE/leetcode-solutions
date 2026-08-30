class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        if(k == n)
            return arr;

        // Find first element >= x
        int right = n;
        int left = 0;

        while(left < right) {
            int mid = left + (right - left) / 2;

            if(arr[mid] < x)
                left = mid + 1;
            else
                right = mid;
        }

        // left is first index >= x
        right = left;
        left = left - 1;

        int count = 0;

        while(count < k) {
            if(left == -1) {
                right++;
            }
            else if(right == n) {
                left--;
            }
            else if(abs(arr[right] - x) < abs(arr[left] - x)) {
                right++;
            }
            else {
                left--;
            }

            count++;
        }

        vector<int> ans;

        for(int i = left + 1; i < right; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};