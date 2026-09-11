class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        long long sumLeft = 0;
        long long sumRight = 0;

        int rightIdx = n/2;

        for(int i=0; i<rightIdx; i++){
            sumLeft += nums[i];
        }
        for(int i=rightIdx; i<n; i++){
            sumRight += nums[i];
        }

        for(int leftIdx=0; leftIdx < n; leftIdx++){
            if(sumLeft > sumRight)
                count++;

            sumLeft  = sumLeft - nums[leftIdx] + nums[rightIdx];
            sumRight = sumRight - nums[rightIdx] + nums[leftIdx];

            rightIdx = (rightIdx + 1) % n;
        }

        return count;
    }
};
