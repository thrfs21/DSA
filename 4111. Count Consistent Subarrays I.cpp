class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            int smallest = nums[i];
            int andOP = nums[i];
            for(int j=i; j<nums.size(); j++) {
                smallest = min(smallest, nums[j]);
                andOP &= nums[j];
                if(andOP == smallest) count++;
            }
        }

        return count;
    }
};
