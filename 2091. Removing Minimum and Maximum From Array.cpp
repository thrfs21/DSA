class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;

        int maxi = nums[0];
        int mini = nums[0];
        int miniIdx = 0;
        int maxiIdx = 0;

        for(int i=0; i<n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxiIdx = i;
            }

            if(nums[i] < mini){
                mini = nums[i];
                miniIdx = i;
            }
        }

        if(miniIdx > maxiIdx){
            swap(miniIdx, maxiIdx);
        }

        return min({n-miniIdx, maxiIdx+1, (miniIdx+1 + n-maxiIdx)});
    }
};
