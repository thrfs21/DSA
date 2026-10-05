class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";

        for(char c : s){
            if(c == '(') count++;
            else count--;

            if(count == 1 && c == '('){
                continue;
            }
            if(count != 0){
                ans += c;
            }
        }

        return ans;
    }
};
