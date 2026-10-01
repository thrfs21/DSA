class Solution {
public:
    bool isValid(string s) {
        vector<char> stack(s.size());
        int top = -1;
        if(s.size() % 2 != 0){
            return false;
        }
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack[++top] = s[i];
            } else{
                if(top == -1){
                    return false;
                }

                if(s[i] == ')' && stack[top] != '(' ||
                    s[i] == '}' && stack[top] != '{' ||
                    s[i] == ']' && stack[top] != '['){
                    return false;
                }
                top--;
            }
        }
        if(top == -1){
            return true;
        } else {
            return false;
        }
    }
};
