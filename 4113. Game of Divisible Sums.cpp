
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();

        vector<long long> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {

            long long s1 = nums[i];

            if (s1 % 3 == 0)
                s1 -= dp[i + 1];
            else
                s1 += dp[i + 1];

            dp[i] = s1;

            if (i + 1 < n) {
                long long s2 = nums[i] + nums[i + 1];

                if (s2 % 3 == 0)
                    s2 -= dp[i + 2];
                else
                    s2 += dp[i + 2];

                dp[i] = max(dp[i], s2);
            }
        }

        return dp[0];
    }
};
