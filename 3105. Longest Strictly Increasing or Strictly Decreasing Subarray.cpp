class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;

        int left = 0;
        for(int right = 1; right < nums.size(); right++) {
            if(nums[right] > nums[right - 1]) {
                inc = max(inc, right - left + 1);
            } else {
                left = right;
            }
        }

        left = 0;
        for(int right = 1; right < nums.size(); right++) {
            if(nums[right] < nums[right - 1]) {
                dec = max(dec, right - left + 1);
            } else {
                left = right;
            }
        }

        return max(inc, dec);
    }
};
