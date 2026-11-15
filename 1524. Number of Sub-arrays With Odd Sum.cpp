class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        long long prefixSum = 0;
        long long even = 1;
        long long odd = 0;

        for(int a : arr) {
            prefixSum += a;

            if(prefixSum % 2) odd++;
            else even++;
        }

        return (even * odd) % MOD;
    }
};
