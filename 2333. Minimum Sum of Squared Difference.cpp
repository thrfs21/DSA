class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(100001, 0);
        long long k = (long long)k1 + k2, sum = 0;
        int maxDiff = 0, n = nums1.size();

        for (int i = 0; i < n; i++) {
            int x = abs(nums1[i] - nums2[i]);
            diff[x]++;
            sum += x;
            maxDiff = max(maxDiff, x);
        }

        if (sum <= k)
            return 0;

        for (int i = maxDiff; i > 0 && k > 0; i--) {
            long long move = min(k, (long long)diff[i]);
            diff[i] -= move;
            diff[i - 1] += move;
            k -= move;
        }

        long long res = 0;

        for (int i = 0; i <= maxDiff; i++) {
            res += 1LL * i * i * diff[i];
        }

        return res;
    }
};
