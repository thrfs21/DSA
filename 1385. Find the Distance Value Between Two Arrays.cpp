class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for(auto x : arr1){
            bool check = true;
            for(auto y : arr2){
                if(abs(x - y) <= d) {
                    check = false;
                    break;
                }
            }

            if(check) count++;
        }

        return count;
    }
};
