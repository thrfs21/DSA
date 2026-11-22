class Solution {
public:
    bool checkString(string s) {
        bool check = false;
        for(char c : s) {
            if(c == 'a' && check) return false;
            else if(c == 'b') check = true;
        }
        return true;
    }
};
