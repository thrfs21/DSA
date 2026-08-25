class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int greatest = *max_element(nums.begin(), nums.end());
        unordered_set<int> set(nums.begin(), nums.end());
        for(int i=1; i<=(greatest/k)+1; i++){
            if(!set.count(i*k)) return i*k;
        }
        return 0;
    }
};
