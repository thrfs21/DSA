class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openIndices;
        string result;

        for(char c : s){
            if(c == '('){
                openIndices.push(result.length());
            }
            else if(c == ')'){
                int start = openIndices.top();
                openIndices.pop();

                reverse(result.begin() + start, result.end());
            }
            else {
                result += c;
            }
        }

        return result;
    }
};
