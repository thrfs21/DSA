class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long score = 0;
        for(int& num : nums){
            num = abs(num);
        }

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            score += nums[right] * nums[right];
            score -= nums[left] * nums[left];
            right--;
            left++;
        }

        if(left == right){
            score += nums[right] * nums[right];
        }

        return score;
    }
};
