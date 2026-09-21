class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k);
        int freq[5] = {0};

        for(auto& n : nums){
            n %= k;
            int curr[5] = {0};

            curr[n] = 1;

            for(int x=0; x<k; x++){
                curr[x * n % k] += freq[x];
            }

            for(int x=0; x<k; x++){
                freq[x] = curr[x];
                res[x] += freq[x];
            }
        }

        return res;
    }
};
