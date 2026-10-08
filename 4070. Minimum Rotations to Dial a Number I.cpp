class Solution {
public:
    int minRotations(string s) {
        int point = 0;
        int ans = 0;

        for(char c : s){
            int num = (c - '0');
            
            int diff = abs(num - point);

            ans += min(diff, 10 - diff);
            
            point = num;
        }

        return ans;
    }
};
