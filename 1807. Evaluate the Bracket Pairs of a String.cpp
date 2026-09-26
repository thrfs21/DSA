class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";

        unordered_map<string, string> mp;
        for(auto& x : knowledge){
            mp[x[0]] = x[1];
        }

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                string temp = "";
                i++;
                while(s[i] != ')'){
                    temp += s[i];
                    i++;
                }
                if(mp.count(temp)){
                    ans += mp[temp];
                } else {
                    ans += '?';
                }
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
