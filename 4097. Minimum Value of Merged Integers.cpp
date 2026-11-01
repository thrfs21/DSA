class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        vector<int> merged;

        for(int i=0; i<nums.size(); i=i+2){
            int num = nums[i];
            int digit = 0;
            int temp = nums[i+1];
            while(temp){
                digit++;
                temp /= 10;
            }

            if(digit != 0){
                num = num * pow(10,digit);
                num += nums[i+1];
            }

            merged.push_back(num);
        }

        return *min_element(merged.begin(), merged.end());
    }
};
