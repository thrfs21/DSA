class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        vector<string> ans;
        int AliceCount = 0;
        int BobCount = 0;
        for(int i=0; i<rain.size()-1; i++) {
            if(rain[i] == 0)
                ans.push_back("None");
            else {
                if(rain[i+1] == 0) {
                    ans.push_back("Bob");
                    BobCount++;
                } else {
                    if(AliceCount > BobCount) {
                        ans.push_back("Bob");
                        BobCount++;
                    } else {
                        ans.push_back("Alice");
                        AliceCount++;
                    }
                }
            }
        }
        rain[rain.size() - 1] == 0 ? ans.push_back("None") : ans.push_back("Bob");

        return ans;
    }
};
