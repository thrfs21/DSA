class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int sum = 0;
            int cnt = 1;

            for (int i = 0; i < nums.size(); i++) {
                if (sum + nums[i] <= mid) {
                    sum += nums[i];
                } else {
                    cnt++;
                    sum = nums[i];
                }
            }

            if (cnt > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
