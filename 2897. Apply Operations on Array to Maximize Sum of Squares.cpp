class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> cnt(30,0);

        for(int num : nums){
            for(int i=0; i<30; i++){
                if(num & (1 << i)){
                    cnt[i]++;
                }
            }
        }

        long long res = 0;
        for(int i=0; i<k; i++){
            long long curr = 0;
            for(int j=29; j>=0; j--){
                if(cnt[j] > 0){
                    curr |= (1LL << j);
                    cnt[j]--;
                }
            }
            res = (res + curr * curr) % MOD;
        }

        return (int)res;
    }
};
