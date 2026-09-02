class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;

        for(int i = 0; i < nums.size(); i++) {
            while(true) {
                if(st.empty()) {
                    st.push(i);
                    break;
                }

                int idx = st.top();

                if(nums[i] > nums[idx]) {
                    res[idx] = nums[i];
                    st.pop();
                } else {
                    st.push(i);
                    break;
                }
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            while(true) {
                if(st.empty()) {
                    st.push(i);
                    break;
                }

                int idx = st.top();

                if(nums[i] > nums[idx]) {
                    res[idx] = nums[i];
                    st.pop();
                } else {
                    st.push(i);
                    break;
                }
            }
        }

        return res;
    }
};