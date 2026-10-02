class Solution {
public:
    void generate(vector<string>& ans, string s, int n, int open, int close){
        if(s.length() == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            generate(ans, s+"(", n, open+1, close);
        }

        if(close < open){
            generate(ans, s+")", n, open, close+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, "", n, 0, 0);
        return ans;
    }
};
